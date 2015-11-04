
public class TestMatrix {

	public static void main(String[] args) {
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
	}
	
	/*
	 * Result Debug:
	 * 	Calculation time Java: 93
     *	Calculation time Native: 390
	 *	Matrix is equal: false
	 *
	 * Result Release:
	 *  Calculation time Java: 171
	 *	Calculation time Native: 94
	 *	Matrix is equal: false
	 */

}
