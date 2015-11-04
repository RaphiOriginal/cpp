
public class Matrix {
	static {
		System.loadLibrary("NativeMatrix");
	}
	
	private double[] matrix;
	public final int row;
	public final int column;
	
	native double[] multiplyC(double[] a, double[] b, double[] r, int i, int j, int k);
	
	public Matrix(int _row, int _column){
		row = _row;
		column = _column;
		matrix = new double[row * column];
		for(int i = 0; i < matrix.length; i++){
			matrix[i] = Math.random(); 
		}
	}
	public Matrix(int _row, int _column, double value){
		row = _row;
		column = _column;
		matrix = new double[row * column];
		for(int i = 0; i < matrix.length; i++){
			matrix[i] = value; 
		}
	}
	
	Matrix multiply(Matrix m){
		Matrix result = new Matrix(this.row, m.column, 0);
		for(int i = 0; i < result.matrix.length; i++){
			for(int j = 0; j < this.row; j++){
				result.matrix[i] += this.matrix[j*this.row + (i % this.row)] * m.matrix[i % m.column + j];
			}
		}
		return result;
	}
	
	Matrix multiplyNative(Matrix m){
		Matrix result = new Matrix(this.row, m.column, 0);
		multiplyC(this.matrix, m.matrix, result.matrix, this.row, m.column, result.matrix.length);
		return result;
	}
	
	boolean equals(Matrix m){
		if(this.row == m.row && this.column == m.column){
			for(int i = 0; i < this.matrix.length; i++){
				if(this.matrix[i] != m.matrix[i]){
					return false;
				}
			}
			return true;
		}
		return false;
	}
}
