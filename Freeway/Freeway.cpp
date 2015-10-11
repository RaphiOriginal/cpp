#include "stdafx.h"
#include <cassert>
#include "Freeway.h"

Freeway::Freeway(Meters dist, Meters sectorLen, Kmh maxSpeed, Meters roadWorksStart, Meters roadWorksLength, Kmh reducedSpeed)
	: m_sectorLen(sectorLen)
	, m_lanes(NLanes)
{
	size_t nSectors = dist / m_sectorLen;

	for (size_t i = 0; i < NLanes; i++) {
		m_lanes[i].reserve(nSectors);

		for (size_t j = 0; j < nSectors; j++) {
			m_lanes[i].emplace_back(maxSpeed);
		}
	}

	// on lane 0
	addRoadWorks(roadWorksStart, roadWorksLength, 0, reducedSpeed);
}

void Freeway::addRoadWorks(Meters start, Meters dist, size_t lane, Kmh maxSpeed) {
	assert(lane < NLanes);
	const Meters forerun = 200;

	// set construction site
	size_t first = Meters(start) / m_sectorLen;
	size_t last = min(m_lanes[lane].size() - 1, first + dist / m_sectorLen);
	assert(first <= last);

	for (size_t i = first; i <= last; i++) {
		m_lanes[lane][i].m_closed = true;
	}

	// set speed on other lane
	auto start2 = max(Meters(0), Meters(start) - forerun);
	first = size_t(start2 / m_sectorLen);

	for (size_t i = first; i <= last; i++) {
		auto& Sector = m_lanes[1 - lane][i];
		Sector.m_maxSpeed = maxSpeed;
		Sector.m_closed = false;
	}
}

bool Freeway::roadWorksAhead(const Position& position, Mps speed, Meters minDist /*= 0*/) const {
	const size_t lane = position.m_lane;
	const Meters pos1 = position.m_pos;
	const Meters pos2 = pos1 + max(minDist, speed*m_freeSight);
	const size_t SectorNr1 = getSectorNr(pos1);
	const size_t SectorNr2 = min(nSectors() - 1, getSectorNr(pos2));

	size_t i = SectorNr1;
	while (i <= SectorNr2 && !m_lanes[lane][i].m_closed) i++;

	return i <= SectorNr2;
}

Meters Freeway::distToRoadWorks(const Position& position) const {
	const size_t lane = position.m_lane;
	const Meters pos = position.m_pos;
	size_t i = getSectorNr(pos);

	if (i < nSectors()) {
		while (!m_lanes[lane][i].m_closed) i++;
	}
	return i*m_sectorLen - pos;
}

Mps Freeway::carSpeed(const Car& car) const {
	SectorInfo si(car.getLane(), min(nSectors() - 1, getSectorNr(car.getPos())));

	return getAllowedSpeed(si)*car.getSpeedFactor();
}
