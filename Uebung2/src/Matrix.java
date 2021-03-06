
public class Matrix {
	static {
		System.loadLibrary("NativeMatrix");
	}
	
	private double[] matrix;
	public final int row;
	public final int column;
	
	native void multiplyC(double[] a, double[] b, double[] r, int i, int j, int k);
	native void powerC(double[] a, double[] r, int i, int d);
	
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
	public Matrix(Matrix m){
		row = m.row;
		column = m.column;
		matrix = m.matrix.clone();
	}
	
	Matrix multiply(Matrix m){
		if(this.column != m.row) return null;
		Matrix result = new Matrix(this.row, m.column, 0);
		
		multiplyCal(m, result);
		
		return result;
	}
	
	Matrix power(int k){
		if(this.row != this.column) return null;
		Matrix result = new Matrix(this);
		Matrix temp = new Matrix(this);
		
		while(k>1){
			temp.multiplyCal(this, result);
			temp = new Matrix(result);
			k--;
		}
		
		return result;
	}
	
	private void multiplyCal(Matrix m, Matrix res){
		//each row from this
		int indexer1 = 0;
		int indexer3 = 0;
		for(int i = 0; i < row; i++){
			//each column from m
			for(int j = 0; j < m.column; j++){
				//next column in this
				int indexer2 = 0;
				double val = 0;
				for(int k = 0; k < column; k++){
					val += matrix[indexer1 + k] * m.matrix[indexer2 + j];
					indexer2 += m.column;
				}
				res.matrix[indexer3++] = val;
			}
			indexer1 += row;
		}
	}
	
	Matrix multiplyNative(Matrix m){
		if(this.column != m.row) return null;
		Matrix result = new Matrix(this.row, m.column, 0);
		multiplyC(this.matrix, m.matrix, result.matrix, m.column, this.row, this.column);
		return result;
	}
	
	Matrix powerNative(int k){
		if(this.row != this.column) return null;
		Matrix result = new Matrix(this);
		powerC(this.matrix, result.matrix, k, this.row);
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
	void print(){
		for(int i = 0; i < row; i++){
			System.out.print("[");
			for(int j = 0; j < column; j++){
				System.out.print(matrix[i*row + j]);
				if(j < column -1) System.out.print(", ");
			}
			System.out.println("]");
		}
		System.out.println();
	}
}
