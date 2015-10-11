#pragma once

#include "Units.h"

const int NColors = 6;
const COLORREF colors[NColors] = { 
	RGB(255, 0, 0), 
	RGB(0, 255, 0), 
	RGB(0, 0, 255), 
	RGB(255, 255, 0), 
	RGB(0, 255, 255), 
	RGB(255, 0, 255) 
};

struct Position {
	size_t m_lane;
	Meters m_pos;

	Position(size_t lane = 0, Meters pos = 0) : m_lane(lane), m_pos(pos) {} //Initialisierungsliste (:) um die Werte zu füllen ohne in den Body zu gehen
	bool operator<(const Position& position) const { return m_pos < position.m_pos || m_pos == position.m_pos && m_lane < position.m_lane; }
};

class Car {
	COLORREF m_color;
	Seconds m_start;
	Position m_position;
	double m_speedFactor;

	static int s_colorIdx;

public:
	Car() : m_color(colors[s_colorIdx++]) { if (s_colorIdx == NColors) s_colorIdx = 0; }

	const COLORREF getColor() const { return m_color; } //mit const (das zweite) darf die instanz nicht geändert werden, (nur lesezugriff)
	const Position& getPosition() const { return m_position; }
	size_t getLane() const { return m_position.m_lane; }
	Meters getPos() const { return m_position.m_pos; }
	double getSpeedFactor() const { return m_speedFactor; }
	const Seconds& getStartTime() const { return m_start; }

	void setPosition(const Position& p) { m_position = p; }
	void setPos(const Meters& m) { m_position.m_pos = m; }
	void addDist(const Meters& m) { m_position.m_pos = m_position.m_pos + m; }
	void changeLane(size_t lane) { m_position.m_lane = lane; }
	void setSpeedFactor(double f) { if (f < 0.75) m_speedFactor = 0.75; else m_speedFactor = f; }
	void start(const Seconds& s) { m_start = s; }
};