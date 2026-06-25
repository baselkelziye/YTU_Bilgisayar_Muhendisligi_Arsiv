package myPackage;

public class DenklemKontrol {
	private String denklem;
	public DenklemKontrol(String denklem) {
		this.denklem=denklem;
	}
	
	
	public boolean isOperator(char o) {
		if(o== '*' || o== '-' || o== '+' || o== '/')
			return true;
		return false;
	}
	
	
	public boolean isEquals(char o) {
		return o=='=';
	}
	
	public boolean isNumber(char o) {
		return (o=='1' || o=='2' || o=='3' ||o=='4' ||o=='5' ||o=='6' ||o=='7' ||o=='8' ||o=='9' ||o=='0');
	}
	public double islemYap(double operand1, double operand2 , char o) {
		switch(o) {
		case '+':
			return operand1+operand2;
		case '-':
			return operand1-operand2;
		case '*':
			return operand1*operand2;
		case '/':
			return operand1/operand2;
		default:
			return operand1+operand2;
	}
	}
	public boolean isPriority(char o) {
		return o=='*' || o== '/';
	}
	
	
	public boolean isCorrect() {
		int flag=0,flag1=0,counter=0,neg=1;
		String result="";
		String[] operand = new String[4];
		String operator="";
		double[] operand1= new double[4];
		for(int i=0;i<4;i++)
			operand[i]="";
		for(int i=0;i<denklem.length();i++) {
			if(isOperator(denklem.charAt(i))) {
					operator=operator+denklem.charAt(i);
					if(flag==1 || flag1==1)
						return false;
					flag=1;}
				
			else if(isEquals(denklem.charAt(i))) {
					if(flag1==1 || flag==1)
						return false;
					flag1=1;
					if(denklem.length()==i+1)
						return false;
					if( denklem.charAt(i+1)=='-') {
						i++;
						neg=-1;
						if(i==denklem.length())
							return false;
					}

						
				}
			else if(isNumber(denklem.charAt(i)) && flag1!=1)  {
				if(flag==1) {
					flag=0;
					counter++;
				}
				operand[counter]=operand[counter]+denklem.charAt(i);
				
			}
			else if(!isNumber(denklem.charAt(i))) {
				return false;
			}
			else {
				result=result+Character.toString(denklem.charAt(i));
			}		
		}
		if(operand[0].length()==0 || flag1!=1) {
			return false;
		}
		for(int i=0;i<4;i++) {
			if(operand[i].length()!=0)
				operand1[i]=Double.parseDouble(operand[i]);
		}
		int intResult=Integer.parseInt(result);
			for(int i=0;i<operator.length();i++)
			if(isPriority(operator.charAt(i))) {
				operand1[i]=islemYap(operand1[i],operand1[i+1],operator.charAt(i));
				operator=operator.substring(0,i)+operator.substring(i+1,operator.length());
				for(int j=i+1;j<operator.length()+1;j++) {
					operand1[j]=operand1[j+1];
				}
				i--;
			}	
			int j;
			for(int i=0;operator.length()!=0;) {
				operand1[i]=islemYap(operand1[i],operand1[i+1],operator.charAt(i));
				operator=operator.substring(0,i)+operator.substring(i+1,operator.length());
	
				for(j=i+1;j<operator.length()+1;j++) {
					operand1[j]=operand1[j+1];
				}
			}
			if(operand1[0]!=(int)operand1[0])
				return false;
		return operand1[0]==neg*intResult;
		
	}
	
}
