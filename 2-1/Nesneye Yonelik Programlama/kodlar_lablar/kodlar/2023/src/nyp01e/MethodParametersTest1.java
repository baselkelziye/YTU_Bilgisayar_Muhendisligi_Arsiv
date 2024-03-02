package nyp01e;

@SuppressWarnings("all")
public class MethodParametersTest1 {
	private Integer wrapI, wrapJ;
	public void ilkelDuzenle( int x ) { x++; }
	public void sarmalayiciDuzenle( Integer x ) { x++; }
	public void ilkelDegistir( int x, int y ) {
		int temp;
		temp = x;
		x = y;
		y = temp;
	}
	public void sarmalayiciDegistir( Integer x, Integer y ) {
		Integer temp; temp = x; x = y; y = temp;
	}
	public void sarmalayiciDegistirAlt(Integer x, Integer y) {
		Integer temp;
		temp = new Integer(x);
		x = new Integer(y);
		y = new Integer(temp);
	}
	public void swapForReal( ) {
		Integer temp = wrapI;
		wrapI = wrapJ;
		wrapJ = temp;
	}
	public static void main(String[] args) {
		MethodParametersTest1 test = new MethodParametersTest1();
		test.tryMe();
	}
	public void tryMe() {
		int count = 3;
		System.out.println("Before : " + count );
		this.ilkelDuzenle(count);
		System.out.println("After: " + count );
		
		Integer wrap = 5;
		System.out.println("Before : " + wrap );
		this.sarmalayiciDuzenle(wrap);
		System.out.println("After: " + wrap );
		
		int count1 = 1, count2 = 2;
		System.out.println("Before : " + count1 + ", " + count2 );
		this.ilkelDegistir(count1, count2);
		System.out.println("After: " + count1 + ", " + count2 );
		
		Integer wrap1 = 1;
		Integer wrap2 = 2;
		System.out.println("Before : " + wrap1 + ", " + wrap2 );
		this.sarmalayiciDegistir(wrap1, wrap2);
		System.out.println("After: " + wrap1 + ", " + wrap2 );

		System.out.println("Before : " + wrap1 + ", " + wrap2 );
		this.sarmalayiciDegistirAlt(wrap1, wrap2);
		System.out.println("After: " + wrap1 + ", " + wrap2 );
		
		wrapI = 3; wrapJ = 5;
		System.out.println("Before : " + wrapI + ", " + wrapJ );
		this.swapForReal();
		System.out.println("After: " + wrapI + ", " + wrapJ );
	}
}
