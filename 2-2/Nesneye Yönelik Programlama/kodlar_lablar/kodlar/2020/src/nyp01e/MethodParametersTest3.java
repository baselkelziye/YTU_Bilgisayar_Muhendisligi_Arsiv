package nyp01e;

public class MethodParametersTest3 {
	public static void main(String[] args) {
		int[] dizi = { 1, 2, 3, 4, 5 };
		LowHighSwap.doIt( dizi );
		for( int j = 0; j < dizi.length; j++ )
			System.out.print( dizi[j] + " " );
	}

}

class LowHighSwap {
	static void doIt( int[] z ) {
		int temp = z[ z.length - 1 ];
		z[ z.length - 1 ] = z[ 0 ];
		z[ 0 ] = temp;
	}
}
/* Using static has nothing to do with the
 * "call-by-value-of-references" issue. */ 