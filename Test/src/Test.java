
public class Test {
	static {
		System.loadLibrary("NativeFunctions");
	}
	public static native void display();
	public static native int increment(int value);
	
	public static void main(String[] args){
		display();
		increment(1);
	}
}
