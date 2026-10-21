#include<stdio.h>
#include<time.h>
int main(){
	int i, j, p, z, k, m, a, b, c, y, t, sekil, A[20][20], sayac=0, skor=0, flag=0, bestskor=0;	
	printf("< MENU >\nSTART(1)\nHOW TO PLAY(2)\nTHE BEST SCORE(3)\nQUIT(4)\n");
	
	while(1){
		
	    scanf("%d", &t);
	    
		if(t==1){
			skor=0;
		    printf("\nPlease enter the row and column numbers you want to play:\n");
    	    printf("Row:");
	        scanf("%d",&p);
	        printf("Column:");	
	        scanf("%d",&z);
	
	        printf("----------\n");
    	    for(i=0; i<p; i++){
	    	    for(j=0; j<z; j++){
		    	    A[i][j]=0;
			        printf(" %d ", A[i][j]);
	        	}
	        	printf("\n");
        	}	
        	printf("----------\n\n");
        	
     	    while(1){	  
     	    
	            srand(time(NULL));
	            sekil=rand()%6;
		
                if(sekil==0){                             //tek kare
                	printf("shape:");
        	        printf("1");
        	        printf("\n");
        	
                	printf("column coordinate:");
	                scanf("%d", &a);
	            
	                i=0;
			        while(i<p){                           
	    	            if(A[i][a-1]==0){
	    	    	        if(i==p-1){
	    	    		        A[i][a-1]=1;
    				    	}
	    			        i=i+1;
		    	        }
			            else{				                      
	    	                A[i-1][a-1]=1;
	    	                break;
	    			    }
	                }
	            }
	    
	            else if(sekil==1){                           //  2'li satýr
	        	    printf("shape: 11   ");
	    	        printf("horizontal->1  vertical->2: ");
	    	        scanf("%d", &y);
	    	        
	            	if(y==1){
		            	printf("column coordinates:");
			            scanf("%d", &a);
    		    	    scanf("%d", &b);
	    		        i=0;
	        		    while(i<p-1){
	    	    		    if(A[i+1][a-1]==0){
	    		    		    if(A[i+1][b-1]==0){
	    			    		    if(i==p-2){
	    				    		    A[i+1][a-1]=1;
	    					    	    A[i+1][b-1]=1;
							        }
     							    i=i+1;
	    					    }
		    				    else{
			    				    A[i][a-1]=1;
	    		    			    A[i][b-1]=1;
	    			    		    break;
						        } 
	    				    }
		    			    else{
			    			    A[i][a-1]=1;
	    		    		    A[i][b-1]=1;
	    			        	break;					
			    	        }
			            }
    		        }
	     	        else if(y==2){
		        	    printf("column coordinate:");
			            scanf("%d", &a);
			            i=0;
			            while(i<p-1){
			    	        if(A[i+1][a-1]==0){
			    		        if(i==p-2){
    						        A[i+1][a-1]=1;
	        		    		    A[i][a-1]=1;
		        				}
			        			i=i+1;			    		
				        	}
					        else{
						        A[i][a-1]=1;
						        A[i-1][a-1]=1;
    						    break;
	    				    }
		    		    }
			        }
    		    }     
	       
	    	    else if(sekil==2){                          //kare
		      	    printf("shape: \n");
			        for(i=0; i<2; i++){
    				    for(j=0; j<2; j++){
	    				    printf("1");
		    		    }
			    	    printf("\n");
        			}       				
	        		printf("\n");
		        	printf("column coordinates:");
			        scanf("%d", &a);
    			    scanf("%d", &b);  
			
    	    		i=0;
	    	    	while(i<p){
		    	    	if(A[i][a-1]==0){
			    	        if(A[i][b-1]==0){
				            	if(i==p-1){
					    	        A[i][a-1]=1;
			                        A[i][b-1]=1;
    			                    A[i-1][a-1]=1;
	    		                    A[i-1][b-1]=1;	
    		    				}						
	    		    			i=i+1;					
		    		    	}	   		
			    	       	else{
				      	    	A[i-1][a-1]=1;				   		
				     		    A[i-1][b-1]=1;				   		
		    		     		A[i-2][a-1]=1;				   		
			    	     		A[i-2][b-1]=1;
				      	    	break;
				        	}				
		        	    }
			            else{
				         	A[i-1][a-1]=1;				   		
				    	    A[i-1][b-1]=1;				   		
			      	    	A[i-2][a-1]=1;				   		
			      		    A[i-2][b-1]=1;
    			   	    	break;
		    		    }			
		            }
                }        
        
    	     	else if(sekil==3){                                            //üçlü satýr
	    	    	printf("shape:  111   (horizontal->1  vertical->2)");			
		    	    printf("1/2?:");
    			    scanf("%d", &y);
	    		
    	    		if(y==1){
	    	    		printf("column coordinates:");
		    	    	scanf("%d", &a);
			        	scanf("%d", &b);
				        scanf("%d", &c);

        				i=0;
	        			while(i<p){
		        			if(A[i][a-1]==0){					
			        	        if(A[i][b-1]==0){
				                	if(A[i][c-1]==0){
				                		if(i==p-1){
				                			A[i][a-1]=1;
						                    A[i][b-1]=1;
						                    A[i][c-1]=1;
	    							    }
		    		    			    i=i+1;			        								
			    		    		}
				    		    	else{					   		    
					        		    A[i-1][a-1]=1;
						                A[i-1][b-1]=1;
						                A[i-1][c-1]=1;
    						            break;
	        						}						    
		        				}
			        			else{				       		
				        		    A[i-1][a-1]=1;
					                A[i-1][b-1]=1;
						            A[i-1][c-1]=1;
	        					    break;
		        				}	
			        		}
				        	else{					
    					        A[i-1][a-1]=1;
	    					    A[i-1][b-1]=1;
		    		    		A[i-1][c-1]=1;
			    		    	break;
				    	    }
		    		    }
			        }			
    	    		else if(y==2){
	    	    		printf("column coordinate:");
		    	    	scanf("%d", &a);
			   	
	    		    	i=2;
		    		    while(i<p){
			    		    if(A[i][a-1]==0){
				    		    if(i==p-1){
					    		    A[i-2][a-1]=1;
    					     		A[i-1][a-1]=1;
	    					    	A[i][a-1]=1;  
        						}
	         					i=i+1;																		
		         			}
			        		else{
				        		A[i-3][a-1]=1;
					        	A[i-2][a-1]=1;
						        A[i-1][a-1]=1;
		        				break;
			        		}					
				        }
	                }	
		        }
		
    		    else if(sekil==4){                             // L 
	    		    printf("shape:\n111\n1\n");
		   	
		        	printf("press 0 or turn right with 1->");
    			    scanf("%d", &y);
    			    
	        		if(y==1){
		        	    printf("column coordinates:");
			            scanf("%d", &a);
			            scanf("%d", &b);
			    
     		    		i=0;
	    		    	while(i<p-1){
		    		    	if(A[i+2][b-1]==0){
    			    			if(A[i][a-1]==0){
	    			    			if(i==p-3){
		    			    			A[i+2][b-1]=1;
			    			    		A[i+1][b-1]=1;
				    			    	A[i][b-1]=1;
					    			    A[i][a-1]=1;
						        	}    
    						        i=i+1;
 	    				     	}
		    		     		else{
			    		    		A[i+1][b-1]=1;
				    		    	A[i][b-1]=1;
					    		    A[i-1][b-1]=1;
					         		A[i-1][a-1]=1;
						        	break;
		         				}
			        		}
				        	else{
					        	A[i+1][b-1]=1;
						        A[i][b-1]=1;
    			    			A[i-1][b-1]=1;
	    			    		A[i-1][a-1]=1;
		    			    	break;
			    		    } 
				        }				
    		    	}
	    		    else if(y==11){
		    		    printf("column coordinates:");
	    	    		scanf("%d",&a);
		        	    scanf("%d",&b);
			        	scanf("%d",&c);
				   
        				i=0;
	        	  		while(i<p-1){
		    	    		if(A[i+1][a-1]==0){
			        			if(A[i+1][b-1]==0){
				        			if(A[i+1][c-1]==0){
					        			if(i==p-2){
						        			A[i+1][a-1]=1;
							                A[i+1][b-1]=1;
								        	A[i+1][c-1]=1;
									        A[i][c-1]=1;
    							    	}
	    							    i=i+1;
	        						}
		        					else{
			        					A[i][a-1]=1;
				        			    A[i][b-1]=1;
					        			A[i][c-1]=1;
						         		A[i-1][c-1]=1;
							         	break;
					    	    	}
				    	    	}
     					    	else{
	    					    	A[i][a-1]=1;
		        				    A[i][b-1]=1;
			        				A[i][c-1]=1;
				         			A[i-1][c-1]=1;
				    	    		break;
		        			    }
		    	    		}
			    	    	else{
				    	    	A[i][a-1]=1;
					            A[i][b-1]=1;
				    	    	A[i][c-1]=1;
					    	    A[i-1][c-1]=1;
			    			    break;
	    		    	    }
		        		}
			        }
        			else if(y==111){
	        			printf("column coordinates:");
		        		scanf("%d", &a);
                     	scanf("%d", &b);
                    	
                     	i=0;
                     	while(i<p-1){
                    		if(A[i+2][a-1]==0){
               	        		if(A[i+2][b-1]==0){
               		        		if(i==p-3){
               		    	    		A[i+2][a-1]=1;
               			    	    	A[i+2][b-1]=1;
               				    	    A[i+1][a-1]=1;
                  					    A[i][a-1]=1;
    	    						}
	    	    				    i=i+1;
		    	    		    }
			    	    	    else{
				    	      	    A[i+1][a-1]=1;
					         	    A[i+1][b-1]=1;
					     	        A[i][a-1]=1;							   					   	     
   				    	   	        A[i-1][a-1]=1;	
    					    		break;				   	    
	         				    }
		        		    }
			        	    else{
				         	    A[i+1][a-1]=1;
				   	            A[i+1][b-1]=1;
				       	        A[i][a-1]=1;							   					   	    
		    		      	    A[i-1][a-1]=1;	
			    	    		break;				   	    
				            }
	    		        }
		    	    }			
		    	    else if(y==0){
			            printf("column coordinates:");
        		    	scanf("%d", &a);
	        		    scanf("%d", &b);
		             	scanf("%d", &c);
			   
        	    		i=0;
	        	    	while(i<p-1){                                 
		        	    	if(A[i+1][a-1]==0){	
			        	    	if(A[i][b-1]==0){
				        	        if(A[i][c-1]==0){
					        	        if(i==p-2){
						            	    A[i+1][a-1]=1;
							                A[i][a-1]=1;
							                A[i][b-1]=1;
			        				        A[i][c-1]=1;
				            		    }
					            	    i=i+1;
					                }
        						    else{							
	        		                    A[i][a-1]=1;
    		        	                A[i-1][a-1]=1;
	    		                        A[i-1][b-1]=1;
		    		        	        A[i-1][c-1]=1;	
			    		                break;
	    		    		    	}
		         	    		}
			        	    	else{									        
				                    A[i][a-1]=1;
     			                    A[i-1][a-1]=1;
	    		                    A[i-1][b-1]=1;
		    		                A[i-1][c-1]=1;		
			   	                    break;
			         		    }	 	        
    			            }
	        			    else{					
		        		        A[i][a-1]=1;
	     	    	            A[i-1][a-1]=1;
		    	                A[i-1][b-1]=1;
			                    A[i-1][c-1]=1;		
			                    break;
        		    		}
	        	        }   
		            }		 
	        	}	   
			 
	         	else if(sekil==5){                               // Z
		        	printf("shape:\n 11\n11\n");			     
    	    		printf("horizontal->1  vertical->2 ");
	     	    	scanf("%d",&y);
		 	   
		        	if(y==1){
			            printf("column coordinates:");
	    		        scanf("%d",&a);
		        	    scanf("%d",&b);
			            scanf("%d",&c);			
	    		        i=0;
		        	    while(i<p-1){
			        	    if(A[i+1][a-1]==0){
				        	    if(A[i+1][b-1]==0){
				            		if(A[i][c-1]==0){
					            		if(i==p-2){
						            		A[i+1][a-1]=1;
							            	A[i+1][b-1]=1;
	    							        A[i][b-1]=1;
    		        						A[i][c-1]=1;
	    		        				}
		    		        			i=i+1;
			    		        	}
		    	    		    	else{		
			    	     		    	A[i][a-1]=1;
	    			         			A[i][b-1]=1;
		    			        		A[i-1][b-1]=1;
			    			        	A[i-1][c-1]=1;
				         			    break;				
					        	    }
			     		        }
   				        	    else{
    				        		A[i][a-1]=1;
	    				        	A[i][b-1]=1;  
    		    			     	A[i-1][b-1]=1;
	         		    			A[i-1][c-1]=1;
		         		    		break;
	    	        			}
		    	        	}
	    	     	    	else{
		    	    	    	A[i][a-1]=1;
			    	    	    A[i][b-1]=1;
			        	    	A[i-1][b-1]=1;
				        	    A[i-1][c-1]=1;
	    				        break;
	        			    }
		        	    }
		            }
		            else if(y==2){
		            	printf("column coordinates:");
			            scanf("%d",&a);
         			    scanf("%d",&b);
         			    
	        	    	i=0;
		            	while(i<p-1){
		            		if(A[i+1][b-1]==0){
		    	         		if(A[i][a-1]==0){
		    		        		if(i==p-2){
		    			        		A[i+1][b-1]=1;
		    				        	A[i][a-1]=1;
		    					        A[i][b-1]=1;		    					
     		         					A[i-1][a-1]=1;
	    			    			}
		    			    		i=i+1;
			    			    }
			        			else{
				        			A[i][b-1]=1;
		    		        		A[i-1][a-1]=1;
		    			        	A[i-1][b-1]=1;		    					
		        				    A[i-2][a-1]=1;
		            				break;
			        			}
				        	}
	    				    else{
		    				    A[i][b-1]=1;
		            			A[i-1][a-1]=1;
		            			A[i-1][b-1]=1;		    					
		    	        		A[i-2][a-1]=1;
		   			         	break;
		                    }
    				    }  
	    		    }     			
		        }
				printf("----------\n");		
	        	for(i=0; i<p; i++){                         //oyun tablosunun yeni halini yazdýrma
	                for(j=0; j<z; j++){
		                printf(" %d ", A[i][j]);
	                }
	                printf("\n");
                }  
		       	       
        		i=p-1;                                       //satýr silme
	            j=0;
	            while(i>0){
    	            while(j<z && A[i][j]==1){
	                    sayac=sayac+1;
	   	                if(sayac==z){
	   	        	        skor=skor+1;
	   	    	            flag=1;
	     	                for(k=i; k>0; k--){
	   			                for(m=0; m<z; m++){
					                A[k][m]=A[k-1][m];
			                    }
				            }
		         		    j=0;
			                sayac=0;
		                }
		                else
		                    j=j+1;
	                }
	    	        if(j<z){
		                i=i-1;
		                j=0;
		                sayac=0;
        		    }
	            }
		        if(flag==1){
				    printf("----------\n");						  
	    	        for(i=0; i<p; i++){
	                    for(j=0; j<z; j++){
	                        printf(" %d ", A[i][j]);
                        }
	                    printf("\n");
                    }
		        } 
		        flag=0;  
	            printf("----------\nscore: %d\n\n", skor);
				if(skor>bestskor){
					bestskor=skor;
				}				 
		        j=0;
	             while((A[0][j]==0) && (j<z)){
    	    	    j=j+1;
	    	    } 
    	    	if(j<z){
	    	    	printf("Game over!\n");
					printf("\nScore: %d\n", skor);
					printf("\nNEW GAME(1)  /  See the highest score(3)  /  QUIT(4):\n");
		    	    break;
	    	    }
	        }            
        }        
        else if(t==2){
        	printf("Enter the column numbers of the given shape where you want to place the shape. The shape is going to go down as possible. When a row is filled completely with 1, your score will raise. Your aim is to get point by filling the rows completely until reaching the row at the bottom.\n\nSTART THE GAME(1):");
		}		
		else if(t==3){
			printf("\nThe best score: %d\nNEW GAME(1)  /  QUIT(4):", bestskor);
		}		
		else if(t==4){
			printf("\nEXITED");
			break;
		}
    }
    return 0; 
}
