package NYO_proje_19011076;

import java.util.*;
import java.lang.*;


public class GenerateEquation {
	static Random randomGenerator = new Random();
    static String operators = "+-*//";
    static int opeatorStringLength = operators.length();
       

    public static char getRandomOperator() {
        return operators.charAt(randomGenerator.nextInt(opeatorStringLength));
    }

    public static int getRandomNumber() {
        return randomGenerator.nextInt(10)+1;
    }
    
    public static int getRandomNumber2() {
        return randomGenerator.nextInt(91)+10;
    }
    
    public static int getRandomNumber3() {
        return randomGenerator.nextInt(901)+100;
    }

    public static String appendToEquation(String equation, String value1, String value2) {
        String temp = equation;
        temp += value1;
        temp += value2;
        return temp;
    }

    public static String createEquation(int numOfOperators) {
    	int[] operandlar = new int[5]; 
    	String equation = "";
        char operator;
        int operand;
        int openParenCounter = 0;
        for (int i = 0; i < numOfOperators; i++) {
            operandlar[0] = getRandomNumber();
            operandlar[1] = getRandomNumber2();
            operandlar[2] = getRandomNumber3();
            operandlar[3] = getRandomNumber();
            operandlar[4] = getRandomNumber2();
            
            operator = getRandomOperator();
            operand = operandlar[randomGenerator.nextInt(4)];
            
            equation = appendToEquation(equation, Integer.toString(operand), Character.toString(operator));
            
        }
        equation += getRandomNumber();
        while (openParenCounter > 0) {
            equation += ")";
            openParenCounter--;
        }
        
        
        String sonuc = evaluate(equation);
        double gecici = Double.parseDouble(sonuc);
        if(gecici != Math.floor(gecici)) {
        	return createEquation(2); 
        }
        sonuc = Integer.toString((int) gecici);
        equation = equation+"="+sonuc;
        System.out.println(equation.length());
        System.out.println(equation);
        if(equation.length()>=7 && equation.length()<=9) {
        	return equation;
        }else {
        	return createEquation(1);
        }
        
    }
    
    /*public static int calculate(String infix) throws ScriptException {    	
    	ScriptEngineManager mgr = new ScriptEngineManager();
        ScriptEngine engine = mgr.getEngineByName("JavaScript");    
        String stringResult;
        try {
            stringResult = engine.eval(infix).toString();
            double doubleResult = Double.parseDouble(stringResult);
            int result = (int) doubleResult;        
            return result;
        } catch (ScriptException ex) {
            //Logger.getLogger(Ukol4a.class.getName()).log(Level.SEVERE, null, ex);
        }
    	ArrayList<String> dizi = new ArrayList<String>();
    	
    	for(String i:equation.split("-")) {
    		dizi.add(i);
    	}
    	
    	
    	for(int i=0;i<dizi.size();i++) {
    		System.out.println(dizi.get(i));
    	}
    	
    	return 1;
    }*/
    
    public static String evaluate(String expression) {
        char[] tokens = expression.toCharArray();
        List<String> list = new ArrayList<>();

        String s = "";

        String operator = "";
        String firstNum = "";
        String secondNum = "";

        boolean operationOnQueue = false;

        for (int i = 0; i < tokens.length; i++) {
            if (Character.isDigit(tokens[i])) {
                s += Character.toString(tokens[i]);
            } else {
                list.add(s);
                list.add(Character.toString(tokens[i]));

                if (operationOnQueue) {
                    operationOnQueue = false;
                    secondNum = s;

                    list.set(list.lastIndexOf(firstNum), eval(firstNum, operator, secondNum));
                    list.remove(list.lastIndexOf(operator));
                    list.remove(list.lastIndexOf(secondNum));
                }

                if (tokens[i] == '*' || tokens[i] == '/') {
                    operationOnQueue = true;

                    operator = Character.toString(tokens[i]);
                    firstNum = list.get(list.lastIndexOf(operator) - 1);
                }

                s = "";
            }

            if (i == tokens.length - 1 && s.length() > 0) {
                list.add(s);

                if (list.get(list.size() - 2).equals("*") || list.get(list.size() - 2).equals("/")) {
                    firstNum = list.get(list.size() - 3);
                    operator = list.get(list.size() - 2);
                    secondNum = list.get(list.size() - 1);

                    list.set(list.size() - 3, eval(firstNum, operator, secondNum));
                    list.remove(list.size() - 2);
                    list.remove(list.size() - 1);
                }
            }
        }


        while (list.size() > 1) {
            firstNum = list.get(0);
            operator = list.get(1);
            secondNum = list.get(2);

            list.set(0, eval(firstNum, operator, secondNum));
            list.remove(2);
            list.remove(1);
        }

        return list.get(0);
    }
    
    public static String eval(String a, String operator, String b) {
        double r = 0;

        switch (operator) {
            case "/":
                r += Double.parseDouble(a) / Double.parseDouble(b);
                break;
            case "*":
                r += Double.parseDouble(a) * Double.parseDouble(b);
                break;
            case "-":
                r += Double.parseDouble(a) - Double.parseDouble(b);
                break;
            case "+":
                r += Double.parseDouble(a) + Double.parseDouble(b);
                break;
        }

        return Double.toString(r);
    }

    public static void main(String[] args) {
        String equation;
        int i=randomGenerator.nextInt(2)+1;
        System.out.println("sonuc:"+i);
        try {
        	equation = createEquation(i);
            System.out.println(equation);
        }catch(IndexOutOfBoundsException e){
        	e.printStackTrace();
        }
        
        
        
    }
}
