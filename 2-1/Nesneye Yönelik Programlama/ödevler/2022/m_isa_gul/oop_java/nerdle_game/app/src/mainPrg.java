import java.util.*;

public class mainPrg {
    public static int random(int min,int max){
        return (int)Math.floor(Math.random()*(max-min+1)+min);
    }
    public static String GenerateEquation() {
        String equation="";
        int int1, int2;
        
    	// Shuffle [2,9] array
        Integer[] twoToNine = {2,3,4,5,6,7,8,9};
        List<Integer> intList = Arrays.asList(twoToNine);
        Collections.shuffle(intList);
        intList.toArray(twoToNine);

        // Integer[] oneToNine = {1,2,3,4,5,6,7,8,9};
        // List<Integer> intList2 = Arrays.asList(oneToNine);
        // Collections.shuffle(intList2);
        // intList2.toArray(oneToNine);
        
        // Create and shuffle [10-99] array
        Integer[] tenToNinetyNine = new Integer[90];
        for(int k=0;k<90;k++){
            tenToNinetyNine[k] = k+10;
        }
        List<Integer> intList3 = Arrays.asList(tenToNinetyNine);
        Collections.shuffle(intList3);
        intList3.toArray(tenToNinetyNine);

        switch (random(7,9)){
            case 7:
                switch (random(0,3)) {
                    case 0: // 7 DIGIT SUM
                        int1 = random(10,90);
                        int2 = random(0,9);
                        switch (random(0,1)) {
                            case 0: // [10-90] + [0-9] = [10-99]
                                equation = int1+"+"+int2+"="+(int1+int2);
                                break;
                            case 1: // [0-9] + [10-90] = [10-99]
                                equation= int2+"+"+int1+"="+(int1+int2);
                        }
                        break;
                        
                    case 1: // 7 DIGIT SUB
                        switch (random(0,2)){
                            case 0: // [19-99] - [0-9] = [10-99]
                                int1 = random(19,99);
                                int2 = random(0,9);
                                equation= int1+"-"+int2+"="+(int1-int2);
                                break;
                            case 1: // [19-99] - [19-99] = [0-9]
                                int1 = random(19,99);
                                int2 = random((int1/10)*10, int1%10-1+(int1/10)*10);
                                equation= int1+"-"+int2+"="+ (int1-int2);
                                break;
                            case 2: // [10-19] - [0-9] = [10-19]
                                int1 = random(10,19);
                                int2 = random(0,int1-10);
                                equation=int1+"-"+int2+"="+(int1-int2);
                                break;
                        }
                        break;
                    case 2: // 7 DIGIT MUL
                        int1 = random(1,9);
                        int2 = random(10,99/int1);
                        switch (random(0,1)) {
                            case 0: // [1-9] * [10-99] = [10-99]
                                equation=int1+"*"+int2+"="+(int1*int2);
                                break;
                            case 1: // [10-99] * [1-9] = [10-99]
                                equation=int2+"*"+int1+"="+(int2*int1);
                                break;
                        }
                        break;

                    case 3: // 7 DIGIT DIV
                        switch(random(0,1)){
                            case 0:
                                int1 = random(10,99);
                                do{
                                    int2 = random(10,int1+10);
                                }while(int1 % int2 !=0);
                                equation=int1+"/"+int2+"="+(int1/int2);
                                break;
                            case 1:
                                int1 = random(10,99);

                                do{
                                    int2 = random(1,9);
                                }while((int1 % int2) !=0 || (int1 / int2) < 10);
                                equation=int1+"/"+int2+"="+(int1/int2);
                                break;
                        }
                        break;
                }
                break;
            case 8:
                switch(random(0,3)){
                    case 0: // 8 DIGIT SUM
                        switch(random(0,1)){
                            case 0:
                                int1 = random(91,99);
                                int2 = random(100-int1,9);
                                switch(random(0,1)){
                                    case 0: // [91-99] + [1-9] = [100-108]
                                        equation=int1+"+"+int2+"="+(int1+int2);
                                        break;
                                    case 1: // [1-9]+ [91-99] = [100-108]
                                        equation=int2+"+"+int1+"="+(int2+int1);
                                        break;
                                }
                                break;
                        
                            case 1: // [10-89] + [10-89] = [10-99]
                                int1 = random(10,89);
                                int2 = random(10,99-int1);
                                equation=int1+"+"+int2+"="+(int1+int2);

                                break;
                        }

                        break;
                    case 1: // 8 DIGIT SUB
                        switch(random(0,1)){
                            case 0: // [20-99] - [10-89] = [10-99]
                                int1 = random(20,99);
                                int2 = random(10,int1-10);
                                equation=int1+"-"+int2+"="+(int1-int2);

                                break;
                            case 1: // [100-108] - [0-9] = [90-99]
                                int1 = random(100,108);
                                int2 = random(int1-99,9);
                                equation=int1+"-"+int2+"="+(int1-int2);
                                break;
                        }
                        break;
                
                    case 2: // 8 DIGIT MUL
                        int1=0;
                        int2=0;
                        while(int2==0){
                            int1 = random(10,99);
                            for(Integer j: twoToNine){
                                if((int1*j>100) && (int1*j<1000)){
                                    int2=j;
                                }
                            }
                        }
                        switch(random(0,1)){
                            case 0: // [10-99] * [2-9] = [100-999]
                                equation=int1+"*"+int2+"="+(int1*int2);
                                break;
                            case 1: // [2-9] * [10-99] = [100-999]
                                equation=int2+"*"+int1+"="+(int2*int1);
                                break;
                            }
                        break;
                    case 3: // 8 DIGIT DIV
                        int1=0;
                        int2=0;
                        while(int2 == 0){
                            int1 = random(100,891);
                            for(Integer j: twoToNine){
                                if(int1 % j == 0 && int1/j > 9 && int1/j < 100){
                                    int2=j;
                                }
                            }
                        }

                        switch(random(0,1)){
                            case 0: // [100-891] / [10-99] = [2-9]
                                equation=int1+"/"+int2+"="+(int1/int2);
                                break;
                            case 1: // [100-891] / [2-9] = [10-99]
                                equation=int1+"/"+(int1/int2)+"="+int2;
                                break;
                        }
                        break;
                    }
                break;
            case 9:
                switch (random(0,3)) {
                    case 0: // 9 DIGIT SUM
                        switch(random(0,1)){
                            case 0: // [50-99] + [50-99] = [100-198]
                                int1 = random(50,99);
                                int2 = random(110-int1,99);
                                equation=int1+"+"+int2+"="+(int1+int2);
                                break;
                            case 1:
                                int1 = random(100,990);
                                int2 = random(0, 9);
                                switch (random(0,1)) {
                                    case 0: // [100-990] + [0-9] = [100-999]
                                        equation=int1+"+"+int2+"="+(int1+int2);
                                        break;
                                
                                    case 1: // [0-9] +[100-990] = [100-999]
                                        equation=int2+"+"+int1+"="+(int2+int1);
                                        break;
                                }
                                break;
                        }
                        break;
                    case 1: // 9 DIGIT SUB
                        switch (random(0,1)) {
                            case 0: // [109-999] - [0-9] = [100-999]
                                    int1 = random(109,999);
                                    int2 = random(0,9);
                                    equation=int1+"-"+int2+"="+(int1-int2);
                                break;
                        
                            case 1: // [110-999] - [10-99] = [10-99]
                                int1 = random(110,198);
                                int2 = random(int1-99,99);
                                equation=int1+"-"+int2+"="+(int1-int2);
                                break;
                        }
                        break;
                    case 2: // 9 DIGIT MUL
                        switch (random(0,1)) {
                            case 0: // [10-99] * [10-99] = [100-999]
                                int1 = random(10,99);
                                int2 = random(10, 999/int1);
                                equation=int1+"*"+int2+"="+(int1*int2);
                                break;
                        
                            case 1:
                                int1 = random(100,999);
                                int2 = random(1, 999/int1);
                                switch (random(0,1)) {
                                    case 0:
                                        equation=int1+"*"+int2+"="+(int1*int2);
                                        break;
                                
                                    case 1:
                                        equation=int2+"*"+int1+"="+(int2*int1);
                                        break;
                                }
                                break;
                        }
                        break;
                
                    case 3: // 9 DIGIT DIV
                        switch (random(0,1)) {
                            case 0: // [100-990] / [10-99] = [10-99]
                                int1=0;
                                int2=0;
                                while(int2 == 0){
                                    int1 = random(100,990);
                                    for(Integer j: tenToNinetyNine){
                                        if(int1 % j == 0 && int1/j > 9 && int1/j < 100){
                                            int2=j;
                                        }
                                    }
                                }
                                equation=int1+"/"+int2+"="+(int1/int2);
                                break;
                        
                            case 1:
                                int1 = 0;
                                int2 = 0;
                                while(int2 == 0){
                                    int1 = random(100,499);
                                    for(Integer j: twoToNine){
                                        if(int1 % j == 0 && int1/j > 100 && int1/j < 1000){
                                            int2=j;
                                        }
                                    }
                                }
                                switch (random(0,1)) {
                                    case 0: // [100-499] / [2-9] = [100-499]
                                        equation=int1+"/"+int2+"="+(int1/int2);
                                        break;
                                
                                    case 1: // [100-499] / [100-499] = [2-9]
                                        equation=int1+"/"+(int1/int2)+"="+int2;
                                        break;
                                }
                                break;
                        }
                        break;
                }
                break;
        }
        return equation;
    }
    

    public static void main(String[] args){
    	System.out.println(GenerateEquation());
    }

    
}