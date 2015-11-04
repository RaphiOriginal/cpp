
public class TestMatrix {

	public static void main(String[] args) {
		
		//test multiply
		Matrix m1 = new Matrix(400, 6000);
		Matrix m2 = new Matrix(6000, 300);
		
		//start Java version
		long start = System.currentTimeMillis();
		Matrix result1 = m1.multiply(m2);
		System.out.println("Calculation time Java: " + (System.currentTimeMillis() - start));
		
		//start Native version
		start = System.currentTimeMillis();
		Matrix result2 = m1.multiplyNative(m2);
		System.out.println("Calculation time Native: " + (System.currentTimeMillis() - start));
		
		//test if equal
		System.out.println("Matrix is equal: " + result1.equals(result2));
		
		//Test pow
		Matrix m3 = new Matrix(200, 200);
		
		//start Java version
		start = System.currentTimeMillis();
		Matrix result3 = m3.power(51);
		System.out.println("power time Java: " + (System.currentTimeMillis() - start));
		
		//start Native version
		start = System.currentTimeMillis();
		//Matrix result4 = powerNative(51);
		System.out.println("power time Native: " + (System.currentTimeMillis() - start));
		
		//test if equal
		//System.out.println("Matrix is equal: " + result3.equals(result4));
		
		Matrix test = new Matrix(2, 2, 2);
		test.power(2).print();
	}
	
	/*
	 * Result Debug:
	 * 	Calculation time Java: 9796
		Calculation time Native: 12200
		Matrix is equal: true
	 *
	 * Result Release:
	 *  Calculation time Java: 10218
		Calculation time Native: 9470
		Matrix is equal: true
	 */

}
