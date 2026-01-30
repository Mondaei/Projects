/* 
	Title: Machine Project: GILGAMESH'S MEGA GIL ADVENTURES
	Author: Keila Franchoise Leigh Ordillas Geslani
	Subject: CCPROG1 S15A
	Date Created: November 09, 2022
	*/
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void skip(int *day) //for skipping the day
{
	printf("---------------------\n");
	printf("You chose to do nothing and skip the day\n");
	printf("-----End of Day %d-----\n", *day);   // pointer day is updated
	printf("=======================\n");
}
	
void tycoonbuy (int *phoenixdown, int *elixiressence, int *platinumingot,int *goldenmateria, 
	int *scarletite, int *adamantite, int *darkmatter,int *trapezohedron, float *balance, int *day, float *debt) // for buying items in tycoon shop
{
	int itemOrder, itemQuantity; // variable for order type and desired quantity, respectively
	char confirm, addOrder; // variables for confirming purchase and additional purchase, respectively
	float total = 0.0; // variable for total cost of orders
	int i;
	int random = rand() % 100 + 1;
	    
	// prices are different in buy and sell because of special items
	time_t t = 0; // required to use srand
	srand((unsigned) time(&t));
	float phoenixDownPrice = (float) rand() / (float) RAND_MAX * (1200 - 500) + 500; // randomized phoenix down price
	float elixiressencePrice = (float) rand() / (float) RAND_MAX * (2100 - 1500) + 1500; // randomized elixir essence price
	float platinumingotPrice = (float) rand() / (float) RAND_MAX * (7000 - 5000) + 5000; // randomized platinum ingot Price
	float goldenmateriaPrice = (float) rand() / (float) RAND_MAX * (5500 - 3500) + 3500; // randomized golden materia price
	float scarletitePrice = (float) rand() / (float) RAND_MAX * (12000 - 8000) + 8000; // randomized scarletite price
	float adamantitePrice = (float) rand() / (float) RAND_MAX * (30000 - 15000) + 15000; // randomized adamantite price
	float darkmatterPrice = (float) rand() / (float) RAND_MAX * (70000 - 40000) + 40000; // randomized dark matter price
	float trapezohedronPrice= (float) rand() / (float) RAND_MAX * (65000 - 35000) + 35000; // SPECIAL ITEM randomized dark matter price
	    
	    // Special Items will never sold out
		if(random < 30 || random == 30){ //has a 30% chance of being sold out.
			phoenixDownPrice = 0;
	    }
	    	if (random < 30 || random == 30) { // has a 30% chance of being sold out.
				elixiressencePrice = 0;
			}
				if(random < 30 || random == 30){ // has a 30% chance of being sold out.
					platinumingotPrice = 0;
				}
					if (random < 30 || random == 30) { // has a 30% chance of being sold out.
						goldenmateriaPrice = 0;
					}
						if(random < 30 || random == 30) { // has a 30% chance of being sold out.
							scarletitePrice = 0;
						}
							if (random < 30 || random == 30){ // has a 30% chance of being sold out.
								adamantitePrice = 0;
							}
								if (random < 30 || random == 30){ // has a 30% chance of being sold out.
									darkmatterPrice = 0;
								}
									
	    
	printf("Shopkeeper: Welcome! How may I be of service?");
	printf ("\n\n");
	printf("Day %d\n" , *day);
	printf("Gil: %.2f \n", *balance);
	printf("Debt: %.2f\n", *debt);
	printf("\t\t\t\t\t       Item        On Hand    Price");
	printf("\n");
	printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
	printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
	
	printf("Note: If you can no longer afford an item, the day will proceed\n\n");
	    
	    do { // this do loop repeats when user wants to order items again & stops when balance is insufficient
	        printf("Shopkeeper: Buying an item? Which one? \n");
	        scanf("%d", &itemOrder);
	        
	        // this segment is for the Phoenix Down item order
	        if(itemOrder == 1) {
	            printf("How many Phoenix Down do you wish to buy?\n");
	            scanf("%d", &itemQuantity);
	            
	            while (itemQuantity * phoenixDownPrice > *balance) { // error handling if balance is not enough
	                printf("Insufficient balance. Only buy what you can afford.\n");
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * phoenixDownPrice;
	            *balance -= total;
	                
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	                
	            printf("Confirm Order? (Y/N) \n");
	            scanf("%c", &confirm); // throughout the program, i placed 2 scanf for char
	            scanf("%c", &confirm); // because it only works if 2 are present instead of 1 (only for char)
	                                   
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *phoenixdown += itemQuantity; // equation for updating the inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);    
	                	          
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of Phoenix Down segment
	        
	        // this segment is for the Elixir Essence item
	        else if(itemOrder == 2) {
	            printf("How many Elixir Essence do you wish to buy?\n");
	            scanf("%d", &itemQuantity);
	            
	            while (itemQuantity * elixiressencePrice > *balance) {
	                printf("Insufficient balance. Only buy what you can afford.\n");  // error handling if
	                scanf("%d", &itemQuantity);                                   // balance is not enough
	            }
	            
	            total = itemQuantity * elixiressencePrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs for char since it won't work if only 1 is placed
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *elixiressence += itemQuantity; // equation for updating the elixir essence inventory
	
	    			
					printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);   
	                	 
	                
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of elixir essence segment
	        
	        // this segment is for the platinum ingot order
	        else if(itemOrder == 3) {
	            printf("How many Platinum Ingot do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * platinumingotPrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * platinumingotPrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *platinumingot += itemQuantity; // equation for updating the platinum inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);    
	                	
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of platinum ingot segment
	               
				    // this segment is for the golden materia order
	        else if(itemOrder == 4) {
	            printf("How many Golden Materia do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * goldenmateriaPrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * goldenmateriaPrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *goldenmateria += itemQuantity; // equation for updating the golden materia inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);     
	                
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of golden materia segment
	        
	        // this segment is for the scarletite order
	        else if(itemOrder == 5) {
	            printf("How many Scarletite do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * scarletitePrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * scarletitePrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *scarletite += itemQuantity; // equation for updating the scarletite inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);     
	                
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of scarletite segment
	        
	        // this segment is for the adamantite order
	        else if(itemOrder == 6) {
	            printf("How many Adamantite do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * adamantitePrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * adamantitePrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *adamantite += itemQuantity; // equation for updating the adamantite inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);     
	                
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of adamantite segment
	        
	                // this segment is for the dark matter order
	        	else if(itemOrder == 7) {
	            printf("How many Dark Matter do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * darkmatterPrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * darkmatterPrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *darkmatter += itemQuantity; // equation for updating the 	 inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);   
	                
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of dark matter segment
	        
	            // this segment is for the trapezohedron order
	        	else if(itemOrder == 8) {
	            printf("How many Trapezohedron do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * trapezohedronPrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * trapezohedronPrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *trapezohedron += itemQuantity; // equation for updating the 	 inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);      
	                
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of trapezohedron segment
	        
	        else if(itemOrder > 8) { // error handling wherein program only allows user to choose between 1-8
	            printf("Choose a number between 1-8 only.\n");
	        }
	                // if balance is < the prices of items, user will not be able to buy again
	        if(*balance < phoenixDownPrice && (*balance < elixiressencePrice && *balance < platinumingotPrice && *balance < goldenmateriaPrice &&
			 *balance < goldenmateriaPrice && *balance < scarletitePrice && *balance < adamantitePrice && *balance < darkmatterPrice && *balance < trapezohedronPrice )){
	            printf("Cannot buy any more items. Balance is insufficient.\n\n");
	        }        
	        // however, if balance is > the prices of items, user is allowed to buy over & over again
	        else if (*balance > phoenixDownPrice || *balance > elixiressencePrice || *balance > platinumingotPrice|| *balance > goldenmateriaPrice
				|| *balance > scarletitePrice || *balance > adamantitePrice || *balance > darkmatterPrice || *balance > trapezohedronPrice){
	            printf("Do you wish to order more items? (Y/N)\n");
	            scanf("%c", &addOrder);
	        }                          // 2 scanf here to make the char work on my compiler
	        
			scanf("%c", &addOrder);
	    } while(addOrder == 'Y' || addOrder == 'y'); // this is the end of the do while loop, repeats once user
	                                                 // wants to order again under certain conditions
	    printf("-----End of Day %d-----\n", *day);   // %d refers to i in the main function, it updates the nth day
	    printf("=======================\n");
	        
}
	
void sellty (int *phoenixdown, int *elixiressence, int *platinumingot,int *goldenmateria, 
	int *scarletite, int *adamantite, int *darkmatter,int *trapezohedron, float *balance, int *day, float *debt) // for selling items in tycoon shop
{
	int i, itemSell, itemQuantity; // variables for the loop and the user's guess in selling, respectively
	float total = 0.0; // variable for total
	char confirm;
	int random = rand() % 100 + 1;
		
	time_t t = 0; // required to use srand
    srand((unsigned) time(&t));
    float phoenixDownPrice = (float) rand() / (float) RAND_MAX * (1200 - 500) + 500; // randomized phoenix down price
    float elixiressencePrice = (float) rand() / (float) RAND_MAX * (2100 - 1500) + 1500; // randomized elixir essence price
	float platinumingotPrice = (float) rand() / (float) RAND_MAX * (7000 - 5000) + 5000; // randomized platinum ingot Price
	float goldenmateriaPrice = (float) rand() / (float) RAND_MAX * (5500 - 3500) + 3500; // randomized golden materia price
	float scarletitePrice = (float) rand() / (float) RAND_MAX * (12000 - 8000) + 8000; // randomized scarletite price
	float adamantitePrice = (float) rand() / (float) RAND_MAX * (30000 - 15000) + 15000; // randomized adamantite price
	float darkmatterPrice = (float) rand() / (float) RAND_MAX * (70000 - 40000) + 40000; // randomized dark matter price
	float trapezohedronPrice= (float) rand() / (float) RAND_MAX * (90000 - 60000) + 60000; // randomized trapezohedron price
	    
	        // Special Items will never sold out
		if(random < 30 || random == 30){ //has a 30% chance of being sold out.
			phoenixDownPrice = 0;
	    }
	    	if (random < 30 || random == 30) { // has a 30% chance of being sold out.
				elixiressencePrice = 0;
			}
				if(random < 30 || random == 30){ // has a 30% chance of being sold out.
					platinumingotPrice = 0;
				}
					if (random < 30 || random == 30) { // has a 30% chance of being sold out.
						goldenmateriaPrice = 0;
					}
						if(random < 30 || random == 30) { // has a 30% chance of being sold out.
							scarletitePrice = 0;
						}
							if (random < 30 || random == 30){ // has a 30% chance of being sold out.
								adamantitePrice = 0;
							}
								if (random < 30 || random == 30){ // has a 30% chance of being sold out.
									darkmatterPrice = 0;
								}
								
	printf("Shopkeeper: Welcome! How may I be of service?");
	printf ("\n\n");
	printf("Day %d\n" , *day);
	printf("Gil: %.2f \n", *balance);
	printf("Debt: %.2f\n", *debt);
	printf("\t\t\t\t\t        Item       On Hand   Price");
	printf("\n");
	printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
	printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
		
		printf("Note: If you chose to type 0, it will end the day");
		
			do { // this do loop repeats when user wants to sell items again & stops when there is no item anymore
			        		printf("Shopkeeper: Selling an item? Which one? \n");
			    			scanf("%d", &itemSell);
			    	
							if (itemSell == 1){	
			    				printf ("How many Phoenix Down do you wish to sell?\n");
			    				scanf("%d", &itemQuantity);
			    		
					    			if (*phoenixdown < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					                	system("pause");
					        		}
					        		else if (itemQuantity > *phoenixdown) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * phoenixDownPrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
						    			printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
										
						            	*phoenixdown -= itemQuantity; // equation for updating the inventory
						            	system("pause");
									}
							} // End of Phoenix Down Sell Segment
					
							else if (itemSell == 2){
				    			printf ("How many Elixir Essence do you wish to sell?\n");
				    			scanf("%d", &itemQuantity);
				    		
						    		if (*elixiressence < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					                	system("pause");
					        		}
					        		else if (itemQuantity > *elixiressence) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * elixiressencePrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
						            	*elixiressence -= itemQuantity; // equation for updating the inventory
						            	system("pause");
									}
							} // End of elixir essence Sell Segment
						
							else if (itemSell == 3)
				    		{
					    		printf ("How many Elixir Essence do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
					    			if (*platinumingot < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					                	system("pause");
					        		}
					        		else if (itemQuantity > *platinumingot) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * platinumingotPrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
						            	*platinumingot -= itemQuantity; // equation for updating the inventory
									}
							} // End of platinum ingot Sell Segment
					
							else if (itemSell == 4)
					    	{
					    		printf ("How many Golden Materia do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
						    		if (*goldenmateria < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					                	system("pause");
					        		}
					        		else if (itemQuantity > *goldenmateria) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * goldenmateriaPrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
						            	*goldenmateria -= itemQuantity; // equation for updating the inventory
									}
							} // End of golden materia Sell Segment
					
							else if (itemSell == 5)
					    	{
					    		printf ("How many Scarletite do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
						    		if (*scarletite < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					        			system("pause");
					        		}
					        		else if (itemQuantity > *scarletite) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * scarletitePrice;
					            		*balance += total;
										printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
						            	*scarletite -= itemQuantity; // equation for updating the inventory
									}
							} // End of scarletite Sell Segment
					
							else if (itemSell == 6)
				    		{
					    		printf ("How many Adamantite do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
						    		if (*adamantite < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					        			system("pause");
					        		}
					        		else if (itemQuantity > *adamantite) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * adamantitePrice;
					            		*balance += total;
										printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
										
						            	*adamantite -= itemQuantity; // equation for updating the inventory
									}
							} // End of adamantite Sell Segment
					
							else if (itemSell == 7)
					    	{
					    		printf ("How many Dark Matter do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
						    		if (*darkmatter < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					        			system("pause");
					        		}
					        		else if (itemQuantity > *adamantite) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * darkmatterPrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
										
						            	*darkmatter -= itemQuantity; // equation for updating the inventory
									}
							} // End of dark matter Sell Segment
					
							else if (itemSell == 8)
					    	{
					    		printf ("How many Trapezohedron do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
					    		if (*trapezohedron < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					        			system("pause");
					        		}
					        		else if (itemQuantity > *adamantite) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * trapezohedronPrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
										
						            	*trapezohedron -= itemQuantity; // equation for updating the inventory
									}
							} // End of trapezohedron Sell Segment
					} while (confirm == 'Y' || confirm == 'y'); // end of this do loop that repeats when user wants to sell items again & stops when there is no item anymore		
	    
		printf("Balance left: %.2f \n", *balance);
	    printf("Debt: %.2f\n", *debt);
	    printf("\n");
	    printf("\t\t\t\t\tPhoenix Down       %dx      (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   	printf("\t\t\t\t\tElixir Essence     %dx      (%.2f)\n", *elixiressence ,elixiressencePrice);
	    printf("\t\t\t\t\tPlatinum Ingot      %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    printf("\t\t\t\t\tGolden Materia       %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
		printf("\t\t\t\t\tScarletite          %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    printf("\t\t\t\t\tAdamantite      %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    printf("\t\t\t\t\tDark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
		printf("\t\t\t\t\tTrapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);    
	    printf("-----End of Day %d-----\n", *day); // updates of balance, inventories, and end of day;
	    
	    system("pause");
}

void shopty (int *phoenixdown, int *elixiressence, int *platinumingot,int *goldenmateria, 
		int *scarletite, int *adamantite, int *darkmatter,int *trapezohedron, float *balance, int *day, float *debt) // for tycoon shop
{
	    int mon;
	    int i;
	    int random = rand() % 100 + 1;
	    
		time_t t = 0; // required to use srand
	    srand((unsigned) time(&t));
	    float phoenixDownPrice = (float) rand() / (float) RAND_MAX * (1200 - 500) + 500; // randomized phoenix down price
	    float elixiressencePrice = (float) rand() / (float) RAND_MAX * (2100 - 1500) + 1500; // randomized elixir essence price
	    float platinumingotPrice = (float) rand() / (float) RAND_MAX * (7000 - 5000) + 5000; // randomized platinum ingot Price
	    float goldenmateriaPrice = (float) rand() / (float) RAND_MAX * (5500 - 3500) + 3500; // randomized golden materia price
	    float scarletitePrice = (float) rand() / (float) RAND_MAX * (12000 - 8000) + 8000; // randomized scarletite price
	    float adamantitePrice = (float) rand() / (float) RAND_MAX * (30000 - 15000) + 15000; // randomized adamantite price
	    float darkmatterPrice = (float) rand() / (float) RAND_MAX * (70000 - 40000) + 40000; // randomized dark matter price
	    float trapezohedronPrice= (float) rand() / (float) RAND_MAX * (90000 - 60000) + 60000; // randomized trapezohedron price
	    
	    	if(random < 30 || random == 30){ //has a 30% chance of being sold out.
			phoenixDownPrice = 0;
	    }
	    	if (random < 30 || random == 30) { // has a 30% chance of being sold out.
				elixiressencePrice = 0;
			}
				if(random < 30 || random == 30){ // has a 30% chance of being sold out.
					platinumingotPrice = 0;
				}
					if (random < 30 || random == 30) { // has a 30% chance of being sold out.
						goldenmateriaPrice = 0;
					}
						if(random < 30 || random == 30) { // has a 30% chance of being sold out.
							scarletitePrice = 0;
						}
							if (random < 30 || random == 30){ // has a 30% chance of being sold out.
								adamantitePrice = 0;
							}
								if (random < 30 || random == 30){ // has a 30% chance of being sold out.
									darkmatterPrice = 0;
								}
	    
	    printf("Shopkeeper: Welcome! How may I be of service?");
	    printf ("\n");
	    printf("Day %d\n" , *day);
	    printf("Gil: %.2f \n", *balance);
	    printf("Debt: %.2f\n", *debt);
	    printf("\t\t\t\t\t    Item       On Hand    Price");
	    printf("\n");
	    printf("\t\t\t\t\tPhoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	    printf("\t\t\t\t\tElixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    printf("\t\t\t\t\tPlatinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    printf("\t\t\t\t\tGolden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    printf("\t\t\t\t\tScarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    printf("\t\t\t\t\tAdamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    printf("\t\t\t\t\tDark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
		printf("\t\t\t\t\tTrapezohedron    %dx     (%.2f)\n\n", *trapezohedron ,trapezohedronPrice);
		
		printf("\t\t\t\t\t[1] Buy\n");
		printf("\t\t\t\t\t[2] Sell\n");
		printf("\t\t\t\t\t[3] Skip Day\n");
	    printf("Your Choice: ");
	    scanf("%d", &mon);
	    
	    switch (mon){
	    	case 1: tycoonbuy (&*phoenixdown, &*elixiressence, &*platinumingot,&*goldenmateria, 
		 &*scarletite, &*adamantite, &*darkmatter, &*trapezohedron, &*balance, &*day, &*debt); break;
	    	case 2: sellty (&*phoenixdown, &*elixiressence, &*platinumingot,&*goldenmateria, 
		 &*scarletite, &*adamantite, &*darkmatter, &*trapezohedron, &*balance, &*day, &*debt); break; 
	    	case 3: skip(&*day);break;
		}
}
	
void pulbuy (int *phoenixdown, int *elixiressence, int *platinumingot,int *goldenmateria, 
		int *scarletite, int *adamantite, int *darkmatter,int *trapezohedron, float *balance, int *day, float *debt) // for buying items in pulsian shop
{
		int itemOrder, itemQuantity; // variable for order type and desired quantity, respectively
	    char confirm, addOrder; // variables for confirming purchase and additional purchase, respectively
	    float total = 0.0; // variable for total cost of orders
	    int random = rand() % 100 + 1;
	    int i;
	    
	    // prices are different in buy and sell because of special items
	    time_t t = 0; // required to use srand
	    srand((unsigned) time(&t));
	    float phoenixDownPrice = (float) rand() / (float) RAND_MAX * (800 - 300) + 300; // SPECIAL ITEM randomized phoenix down price 
	    float elixiressencePrice = (float) rand() / (float) RAND_MAX * (1700 - 1000) + 1000; // SPECIAL ITEM randomized elixir essence price
	    float platinumingotPrice = (float) rand() / (float) RAND_MAX * (7000 - 5000) + 5000; // randomized platinum ingot Price
	    float goldenmateriaPrice = (float) rand() / (float) RAND_MAX * (5500 - 3500) + 3500; // randomized golden materia price
	    float scarletitePrice = (float) rand() / (float) RAND_MAX * (12000 - 8000) + 8000; // randomized scarletite price
	    float adamantitePrice = (float) rand() / (float) RAND_MAX * (30000 - 15000) + 15000; // randomized adamantite price
	    float darkmatterPrice = (float) rand() / (float) RAND_MAX * (70000 - 40000) + 40000; // randomized dark matter price
	    float trapezohedronPrice= (float) rand() / (float) RAND_MAX * (90000 - 60000) + 60000; // randomized dark matter price
	    
	        	// Special items will never sold out
				if(random < 30 || random == 30){ // has a 30% chance of being sold out.
					platinumingotPrice = 0;
				}
					if (random < 30 || random == 30) { // has a 30% chance of being sold out.
						goldenmateriaPrice = 0;
					}
						if(random < 30 || random == 30) { // has a 30% chance of being sold out.
							scarletitePrice = 0;
						}
							if (random < 30 || random == 30){ // has a 30% chance of being sold out.
								adamantitePrice = 0;
							}
								if (random < 30 || random == 30){ // has a 30% chance of being sold out.
									darkmatterPrice = 0;
								}
									if (random < 30 ){ // has a 30% chance of being sold out.
												trapezohedronPrice= 0;
											}
	    
	    printf("Shopkeeper: Welcome! How may I be of service?");
	    printf ("\n\n");
	    printf("Day %d\n" , *day);
	    printf("Gil: %.2f \n", *balance);
	    printf("Debt: %.2f\n", *debt);
	    printf("\t\t\t\t\t       Item        On Hand    Price");
	    printf("\n");
	    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
		printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
	
	    printf("Note: If you can no longer afford an item, the day will proceed\n\n");
	    
	    do { // this do loop repeats when user wants to order items again & stops when balance is insufficient
	        printf("Shopkeeper: Buying an item? Which one? \n");
	        scanf("%d", &itemOrder);
	        
	        // this segment is for the Phoenix Down item order
	        if(itemOrder == 1) {
	            printf("How many Phoenix Down do you wish to buy?\n");
	            scanf("%d", &itemQuantity);
	            
	            while (itemQuantity * phoenixDownPrice > *balance) { // error handling if balance is not enough
	                printf("Insufficient balance. Only buy what you can afford.\n");
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * phoenixDownPrice;
	            *balance -= total;
	                
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	                
	            printf("Confirm Order? (Y/N) \n");
	            scanf("%c", &confirm); // throughout the program, i placed 2 scanf for char
	            scanf("%c", &confirm); // because it only works if 2 are present instead of 1 (only for char)
	                                   
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *phoenixdown += itemQuantity; // equation for updating the inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);   
	                        
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of Phoenix Down segment
	        
	        // this segment is for the Elixir Essence item
	        else if(itemOrder == 2) {
	            printf("How many Elixir Essence do you wish to buy?\n");
	            scanf("%d", &itemQuantity);
	            
	            while (itemQuantity * elixiressencePrice > *balance) {
	                printf("Insufficient balance. Only buy what you can afford.\n");  // error handling if
	                scanf("%d", &itemQuantity);                                   // balance is not enough
	            }
	            
	            total = itemQuantity * elixiressencePrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs for char since it won't work if only 1 is placed
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *elixiressence += itemQuantity; // equation for updating the elixir essence inventory
	
	    			
					printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);    
	                printf("\t\t\t\t\tBalance left: %.2f \n", *balance); 
	                
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of elixir essence segment
	        
	        // this segment is for the platinum ingot order
	        else if(itemOrder == 3) {
	            printf("How many Platinum Ingot do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * platinumingotPrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * platinumingotPrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *platinumingot += itemQuantity; // equation for updating the 	 inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);    
	                printf("\t\t\t\t\t Balance left: %.2f \n", *balance);
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of platinum ingot segment
	               
				    // this segment is for the golden materia order
	        else if(itemOrder == 4) {
	            printf("How many Golden Materia do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * goldenmateriaPrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * goldenmateriaPrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *goldenmateria += itemQuantity; // equation for updating the 	 inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx      (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx      (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot      %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia       %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite          %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite      %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);    
	                
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of golden materia segment
	        
	        // this segment is for the scarletite order
	        else if(itemOrder == 5) {
	            printf("How many Scarletite do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * scarletitePrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * scarletitePrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *scarletite += itemQuantity; // equation for updating the 	 inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx      (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx      (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot      %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia       %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite          %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite      %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);    
	                
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of scarletite segment
	        
	        // this segment is for the adamantite order
	        else if(itemOrder == 6) {
	            printf("How many Adamantite do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * adamantitePrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * adamantitePrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *adamantite += itemQuantity; // equation for updating the 	 inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);   
	                
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of adamantite segment
	        
	                // this segment is for the dark matter order
	        	else if(itemOrder == 7) {
	            printf("How many Dark Matter do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * darkmatterPrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * darkmatterPrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *darkmatter += itemQuantity; // equation for updating the 	 inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);  
	                
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of dark matter segment
	        
	            // this segment is for the trapezohedron order
	        	else if(itemOrder == 8) {
	            printf("How many Trapezohedron do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * trapezohedronPrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * trapezohedronPrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *trapezohedron += itemQuantity; // equation for updating the 	 inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);     
	                
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of trapezohedron segment
	        
	        else if(itemOrder > 8) { // error handling wherein program only allows user to choose between 1-8
	            printf("Choose a number between 1-8 only.\n");
	        }
	                // if balance is < the prices of items, user will not be able to buy again
	        if(*balance < phoenixDownPrice && (*balance < elixiressencePrice && *balance < platinumingotPrice && *balance < goldenmateriaPrice &&
			 *balance < goldenmateriaPrice && *balance < scarletitePrice && *balance < adamantitePrice && *balance < darkmatterPrice && *balance < trapezohedronPrice )){
	            printf("Cannot buy any more items. Balance is insufficient.\n\n");
	        }        
	        // however, if balance is > the prices of items, user is allowed to buy over & over again
	        else if (*balance > phoenixDownPrice || *balance > elixiressencePrice || *balance > platinumingotPrice|| *balance > goldenmateriaPrice
				|| *balance > scarletitePrice || *balance > adamantitePrice || *balance > darkmatterPrice || *balance > trapezohedronPrice){
	            printf("Do you wish to order more items? (Y/N)\n");
	            scanf("%c", &addOrder);
	        }                          // 2 scanf here to make the char work on my compiler
	        
			scanf("%c", &addOrder);
	    } while(addOrder == 'Y' || addOrder == 'y'); // this is the end of the do while loop, repeats once user
	                                                 // wants to order again under certain conditions
	    printf("-----End of Day %d-----\n", *day);   // %d refers to i in the main function, it updates the nth day
	    printf("=======================\n");
	    
	    
}
	
void sellpul (int *phoenixdown, int *elixiressence, int *platinumingot,int *goldenmateria, 
		int *scarletite, int *adamantite, int *darkmatter,int *trapezohedron, float *balance, int *day, float *debt) // for selling items in pulsian shop
{
		int i, itemSell, itemQuantity; // variables for the loop and the user's guess in selling, respectively
		float total = 0.0; // variable for total
		char confirm;
		int random = rand() % 100 + 1;
		
		
		time_t t = 0; // required to use srand
	    srand((unsigned) time(&t));
	    float phoenixDownPrice = (float) rand() / (float) RAND_MAX * (1200 - 500) + 500; // randomized phoenix down price
	    float elixiressencePrice = (float) rand() / (float) RAND_MAX * (2100 - 1500) + 1500; // randomized elixir essence price
	    float platinumingotPrice = (float) rand() / (float) RAND_MAX * (7000 - 5000) + 5000; // randomized platinum ingot Price
	    float goldenmateriaPrice = (float) rand() / (float) RAND_MAX * (5500 - 3500) + 3500; // randomized golden materia price
	    float scarletitePrice = (float) rand() / (float) RAND_MAX * (12000 - 8000) + 8000; // randomized scarletite price
	    float adamantitePrice = (float) rand() / (float) RAND_MAX * (30000 - 15000) + 15000; // randomized adamantite price
	    float darkmatterPrice = (float) rand() / (float) RAND_MAX * (70000 - 40000) + 40000; // randomized dark matter price
	    float trapezohedronPrice= (float) rand() / (float) RAND_MAX * (90000 - 60000) + 60000; // randomized trapezohedron price
	    
	            	// Special items will never sold out
				if(random < 30 || random == 30){ // has a 30% chance of being sold out.
					platinumingotPrice = 0;
				}
					if (random < 30 || random == 30) { // has a 30% chance of being sold out.
						goldenmateriaPrice = 0;
					}
						if(random < 30 || random == 30) { // has a 30% chance of being sold out.
							scarletitePrice = 0;
						}
							if (random < 30 || random == 30){ // has a 30% chance of being sold out.
								adamantitePrice = 0;
							}
								if (random < 30 || random == 30){ // has a 30% chance of being sold out.
									darkmatterPrice = 0;
								}
									if (random < 30 ){ // has a 30% chance of being sold out.
												trapezohedronPrice= 0;
											}
	    
	    printf("Shopkeeper: Welcome! How may I be of service?");
	    printf ("\n\n");
	    printf("Day %d\n" , *day);
	    printf("Gil: %.2f \n", *balance);
	    printf("Debt: %.2f\n", *debt);
	    printf("\t\t\t\t\t        Item       On Hand   Price");
	    printf("\n");
	    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
		printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
		
		printf("Note: If you chose to type 0, it will end the day");
		
			do { // this do loop repeats when user wants to sell items again & stops when there is no item anymore
			        		printf("Shopkeeper: Selling an item? Which one? \n");
			    			scanf("%d", &itemSell);
			    	
							if (itemSell == 1){	
			    				printf ("How many Phoenix Down do you wish to sell?\n");
			    				scanf("%d", &itemQuantity);
			    		
					    			if (*phoenixdown < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					                	system("pause");
					        		}
					        		else if (itemQuantity > *phoenixdown) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * phoenixDownPrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
						    			printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
										
						            	*phoenixdown -= itemQuantity; // equation for updating the inventory
						            	system("pause");
									}
							} // End of Phoenix Down Sell Segment
					
							else if (itemSell == 2){
				    			printf ("How many Elixir Essence do you wish to sell?\n");
				    			scanf("%d", &itemQuantity);
				    		
						    		if (*elixiressence < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					                	system("pause");
					        		}
					        		else if (itemQuantity > *elixiressence) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * elixiressencePrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
						            	*elixiressence -= itemQuantity; // equation for updating the inventory
						            	system("pause");
									}
							} // End of elixir essence Sell Segment
						
							else if (itemSell == 3)
				    		{
					    		printf ("How many Elixir Essence do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
					    			if (*platinumingot < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					                	system("pause");
					        		}
					        		else if (itemQuantity > *platinumingot) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * platinumingotPrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
						            	*platinumingot -= itemQuantity; // equation for updating the inventory
									}
							} // End of platinum ingot Sell Segment
					
							else if (itemSell == 4)
					    	{
					    		printf ("How many Golden Materia do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
						    		if (*goldenmateria < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					                	system("pause");
					        		}
					        		else if (itemQuantity > *goldenmateria) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * goldenmateriaPrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
						            	*goldenmateria -= itemQuantity; // equation for updating the inventory
									}
							} // End of golden materia Sell Segment
					
							else if (itemSell == 5)
					    	{
					    		printf ("How many Scarletite do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
						    		if (*scarletite < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					        			system("pause");
					        		}
					        		else if (itemQuantity > *scarletite) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * scarletitePrice;
					            		*balance += total;
										printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
						            	*scarletite -= itemQuantity; // equation for updating the inventory
									}
							} // End of scarletite Sell Segment
					
							else if (itemSell == 6)
				    		{
					    		printf ("How many Adamantite do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
						    		if (*adamantite < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					        			system("pause");
					        		}
					        		else if (itemQuantity > *adamantite) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * adamantitePrice;
					            		*balance += total;
										printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
										
						            	*adamantite -= itemQuantity; // equation for updating the inventory
									}
							} // End of adamantite Sell Segment
					
							else if (itemSell == 7)
					    	{
					    		printf ("How many Dark Matter do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
						    		if (*darkmatter < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					        			system("pause");
					        		}
					        		else if (itemQuantity > *adamantite) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * darkmatterPrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
										
						            	*darkmatter -= itemQuantity; // equation for updating the inventory
									}
							} // End of dark matter Sell Segment
					
							else if (itemSell == 8)
					    	{
					    		printf ("How many Trapezohedron do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
					    		if (*trapezohedron < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					        			system("pause");
					        		}
					        		else if (itemQuantity > *adamantite) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * trapezohedronPrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
										
						            	*trapezohedron -= itemQuantity; // equation for updating the inventory
									}
							} // End of trapezohedron Sell Segment
					} while (confirm == 'Y' || confirm == 'y'); // end of this do loop that repeats when user wants to sell items again & stops when there is no item anymore		
	    
		printf("Balance left: %.2f \n", *balance);
	    printf("Debt: %.2f\n", *debt);
	    printf("\n");
	    printf("\t\t\t\t\tPhoenix Down       %dx      (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   	printf("\t\t\t\t\tElixir Essence     %dx      (%.2f)\n", *elixiressence ,elixiressencePrice);
	    printf("\t\t\t\t\tPlatinum Ingot      %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    printf("\t\t\t\t\tGolden Materia       %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
		printf("\t\t\t\t\tScarletite          %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    printf("\t\t\t\t\tAdamantite      %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    printf("\t\t\t\t\tDark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
		printf("\t\t\t\t\tTrapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);    
	    printf("-----End of Day %d-----\n", *day); // updates of balance, inventories, and end of day;
	    
	    system("pause");
}
	
void shoppul (int *phoenixdown, int *elixiressence, int *platinumingot,int *goldenmateria, 
	int *scarletite, int *adamantite, int *darkmatter,int *trapezohedron, float *balance, int *day, float *debt) // for pulsian shop
{
	    int mon;
	    int random = rand() % 100 + 1;
	    int i;
	    
	    
		time_t t = 0; // required to use srand
	    srand((unsigned) time(&t));
	    float phoenixDownPrice = (float) rand() / (float) RAND_MAX * (1200 - 500) + 500; // randomized phoenix down price
	    float elixiressencePrice = (float) rand() / (float) RAND_MAX * (2100 - 1500) + 1500; // randomized elixir essence price
	    float platinumingotPrice = (float) rand() / (float) RAND_MAX * (7000 - 5000) + 5000; // randomized platinum ingot Price
	    float goldenmateriaPrice = (float) rand() / (float) RAND_MAX * (5500 - 3500) + 3500; // randomized golden materia price
	    float scarletitePrice = (float) rand() / (float) RAND_MAX * (12000 - 8000) + 8000; // randomized scarletite price
	    float adamantitePrice = (float) rand() / (float) RAND_MAX * (30000 - 15000) + 15000; // randomized adamantite price
	    float darkmatterPrice = (float) rand() / (float) RAND_MAX * (70000 - 40000) + 40000; // randomized dark matter price
	    float trapezohedronPrice= (float) rand() / (float) RAND_MAX * (90000 - 60000) + 60000; // randomized trapezohedron price
	    
	            	// Special items will never sold out
				if(random < 30 || random == 30){ // has a 30% chance of being sold out.
					platinumingotPrice = 0;
				}
					if (random < 30 || random == 30) { // has a 30% chance of being sold out.
						goldenmateriaPrice = 0;
					}
						if(random < 30 || random == 30) { // has a 30% chance of being sold out.
							scarletitePrice = 0;
						}
							if (random < 30 || random == 30){ // has a 30% chance of being sold out.
								adamantitePrice = 0;
							}
								if (random < 30 || random == 30){ // has a 30% chance of being sold out.
									darkmatterPrice = 0;
								}
									if (random < 30 ){ // has a 30% chance of being sold out.
												trapezohedronPrice= 0;
											}
	    
	    printf("Shopkeeper: Welcome! How may I be of service?");
	    printf ("\n");
	    printf("Day %d\n" , *day);
	    printf("Gil: %.2f \n", *balance);
	    printf("Debt: %.2f\n", *debt);
	    printf("\t\t\t\t\t    Item       On Hand    Price");
	    printf("\n");
	    printf("\t\t\t\t\tPhoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	    printf("\t\t\t\t\tElixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    printf("\t\t\t\t\tPlatinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    printf("\t\t\t\t\tGolden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    printf("\t\t\t\t\tScarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    printf("\t\t\t\t\tAdamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    printf("\t\t\t\t\tDark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
		printf("\t\t\t\t\tTrapezohedron    %dx     (%.2f)\n\n", *trapezohedron ,trapezohedronPrice);
		
		printf ("Note: If you try to sell even if you don't have an item in your inventory it will skip the day\n");
		printf ("so make sure you have atleast 1 in your inventory when selling.\n\n");
		
		printf("\t\t\t\t\t[1] Buy\n");
		printf("\t\t\t\t\t[2] Sell\n");
		printf("\t\t\t\t\t[3] Skip Day\n");
	    printf("Your Choice: ");
	    scanf("%d", &mon);
	    
	    switch (mon){
	    	case 1: pulbuy (&*phoenixdown, &*elixiressence, &*platinumingot,&*goldenmateria, 
		 &*scarletite, &*adamantite, &*darkmatter, &*trapezohedron, &*balance, &*day, &*debt); break;
	    	case 2: sellpul (&*phoenixdown, &*elixiressence, &*platinumingot,&*goldenmateria, 
		 &*scarletite, &*adamantite, &*darkmatter, &*trapezohedron, &*balance, &*day, &*debt); break; 
	    	case 3: skip(&*day);break;
		}
}
	
void archbuy (int *phoenixdown, int *elixiressence, int *platinumingot,int *goldenmateria, 
	int *scarletite, int *adamantite, int *darkmatter,int *trapezohedron, float *balance, int *day, float *debt) // for buying items in archadian shop
{
		int itemOrder, itemQuantity; // variable for order type and desired quantity, respectively
	    char confirm, addOrder; // variables for confirming purchase and additional purchase, respectively
	    float total = 0.0; // variable for total cost of orders
	    int random = rand() % 100 + 1;
	    int i;
	    
	    // prices are different in buy and sell because of special items
	    time_t t = 0; // required to use srand
	    srand((unsigned) time(&t));
	    float phoenixDownPrice = (float) rand() / (float) RAND_MAX * (1200 - 500) + 500; // randomized phoenix down price
	    float elixiressencePrice = (float) rand() / (float) RAND_MAX * (2100 - 1500) + 1500; // randomized elixir essence price
	    float platinumingotPrice = (float) rand() / (float) RAND_MAX * (6000 - 4500) + 4500; // SPECIAL ITEM randomized platinum ingot Price
	    float goldenmateriaPrice = (float) rand() / (float) RAND_MAX * (5500 - 3500) + 3500; // randomized golden materia price
	    float scarletitePrice = (float) rand() / (float) RAND_MAX * (12000 - 8000) + 8000; // randomized scarletite price
	    float adamantitePrice = (float) rand() / (float) RAND_MAX * (30000 - 15000) + 15000; // randomized adamantite price
	    float darkmatterPrice = (float) rand() / (float) RAND_MAX * (70000 - 40000) + 40000; // randomized dark matter price
	    float trapezohedronPrice= (float) rand() / (float) RAND_MAX * (90000 - 60000) + 60000; // randomized dark matter price
	    
	        	//Special items will never sold out
			if(random < 30 || random == 30){ //has a 30% chance of being sold out.
			phoenixDownPrice = 0;
	    }
	    	if (random < 30 || random == 30) { // has a 30% chance of being sold out.
				elixiressencePrice = 0;
			}
					if (random < 30 || random == 30) { // has a 30% chance of being sold out.
						goldenmateriaPrice = 0;
					}
						if(random < 30 || random == 30) { // has a 30% chance of being sold out.
							scarletitePrice = 0;
						}
							if (random < 30 || random == 30){ // has a 30% chance of being sold out.
								adamantitePrice = 0;
							}
								if (random < 30 || random == 30){ // has a 30% chance of being sold out.
									darkmatterPrice = 0;
								}
									if (random < 30 ){ // has a 30% chance of being sold out.
												trapezohedronPrice= 0;
											}
	    
	    printf("Shopkeeper: Welcome! How may I be of service?");
	    printf ("\n\n");
	    printf("Day %d\n" , *day);
	    printf("Gil: %.2f \n", *balance);
	    printf("Debt: %.2f\n", *debt);
	    printf("\t\t\t\t\t       Item        On Hand    Price");
	    printf("\n");
	    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
		printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
	
	    printf("Note: If you can no longer afford an item, the day will proceed\n\n");
	    
	    do { // this do loop repeats when user wants to order items again & stops when balance is insufficient
	        printf("Shopkeeper: Buying an item? Which one? \n");
	        scanf("%d", &itemOrder);
	        
	        // this segment is for the Phoenix Down item order
	        if(itemOrder == 1) {
	            printf("How many Phoenix Down do you wish to buy?\n");
	            scanf("%d", &itemQuantity);
	            
	            while (itemQuantity * phoenixDownPrice > *balance) { // error handling if balance is not enough
	                printf("Insufficient balance. Only buy what you can afford.\n");
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * phoenixDownPrice;
	            *balance -= total;
	                
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	                
	            printf("Confirm Order? (Y/N) \n");
	            scanf("%c", &confirm); // throughout the program, i placed 2 scanf for char
	            scanf("%c", &confirm); // because it only works if 2 are present instead of 1 (only for char)
	                                   
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *phoenixdown += itemQuantity; // equation for updating the inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);    
	                printf("\t\t\t\t\t Balance left: %.2f \n", *balance);          
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of Phoenix Down segment
	        
	        // this segment is for the Elixir Essence item
	        else if(itemOrder == 2) {
	            printf("How many Elixir Essence do you wish to buy?\n");
	            scanf("%d", &itemQuantity);
	            
	            while (itemQuantity * elixiressencePrice > *balance) {
	                printf("Insufficient balance. Only buy what you can afford.\n");  // error handling if
	                scanf("%d", &itemQuantity);                                   // balance is not enough
	            }
	            
	            total = itemQuantity * elixiressencePrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs for char since it won't work if only 1 is placed
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *elixiressence += itemQuantity; // equation for updating the elixir essence inventory
	
	    			
					printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);  
	                
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of elixir essence segment
	        
	        // this segment is for the platinum ingot order
	        else if(itemOrder == 3) {
	            printf("How many Platinum Ingot do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * platinumingotPrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * platinumingotPrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *platinumingot += itemQuantity; // equation for updating the 	 inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);  
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of platinum ingot segment
	               
				    // this segment is for the golden materia order
	        else if(itemOrder == 4) {
	            printf("How many Golden Materia do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * goldenmateriaPrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * goldenmateriaPrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *goldenmateria += itemQuantity; // equation for updating the 	 inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);  
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of golden materia segment
	        
	        // this segment is for the scarletite order
	        else if(itemOrder == 5) {
	            printf("How many Scarletite do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * scarletitePrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * scarletitePrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *scarletite += itemQuantity; // equation for updating the 	 inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);  
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of scarletite segment
	        
	        // this segment is for the adamantite order
	        else if(itemOrder == 6) {
	            printf("How many Adamantite do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * adamantitePrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * adamantitePrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *adamantite += itemQuantity; // equation for updating the 	 inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);  
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of adamantite segment
	        
	                // this segment is for the dark matter order
	        	else if(itemOrder == 7) {
	            printf("How many Dark Matter do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * darkmatterPrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * darkmatterPrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *darkmatter += itemQuantity; // equation for updating the 	 inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);  
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of dark matter segment
	        
	            // this segment is for the trapezohedron order
	        	else if(itemOrder == 8) {
	            printf("How many Trapezohedron do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * trapezohedronPrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * trapezohedronPrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *trapezohedron += itemQuantity; // equation for updating the 	 inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);  
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of trapezohedron segment
	        
	        else if(itemOrder > 8) { // error handling wherein program only allows user to choose between 1-8
	            printf("Choose a number between 1-8 only.\n");
	        }
	                // if balance is < the prices of items, user will not be able to buy again
	        if(*balance < phoenixDownPrice && (*balance < elixiressencePrice && *balance < platinumingotPrice && *balance < goldenmateriaPrice &&
			 *balance < goldenmateriaPrice && *balance < scarletitePrice && *balance < adamantitePrice && *balance < darkmatterPrice && *balance < trapezohedronPrice )){
	            printf("Cannot buy any more items. Balance is insufficient.\n\n");
	        }        
	        // however, if balance is > the prices of items, user is allowed to buy over & over again
	        else if (*balance > phoenixDownPrice || *balance > elixiressencePrice || *balance > platinumingotPrice|| *balance > goldenmateriaPrice
				|| *balance > scarletitePrice || *balance > adamantitePrice || *balance > darkmatterPrice || *balance > trapezohedronPrice){
	            printf("Do you wish to order more items? (Y/N)\n");
	            scanf("%c", &addOrder);
	        }                          // 2 scanf here to make the char work on my compiler
	        
			scanf("%c", &addOrder);
	    } while(addOrder == 'Y' || addOrder == 'y'); // this is the end of the do while loop, repeats once user
	                                                 // wants to order again under certain conditions
	    printf("-----End of Day %d-----\n", *day);   // %d refers to i in the main function, it updates the nth day
	    printf("=======================\n");
	    
	    
}
	
void sellarch (int *phoenixdown, int *elixiressence, int *platinumingot,int *goldenmateria, 
	int *scarletite, int *adamantite, int *darkmatter,int *trapezohedron, float *balance, int *day, float *debt) // for selling items in archadian shop
{
		int i, itemSell, itemQuantity; // variables for the loop and the user's guess in selling, respectively
		float total = 0.0; // variable for total
		char confirm;
		int random = rand() % 100 + 1;
		
		time_t t = 0; // required to use srand
	    srand((unsigned) time(&t));
	    float phoenixDownPrice = (float) rand() / (float) RAND_MAX * (1200 - 500) + 500; // randomized phoenix down price
	    float elixiressencePrice = (float) rand() / (float) RAND_MAX * (2100 - 1500) + 1500; // randomized elixir essence price
	    float platinumingotPrice = (float) rand() / (float) RAND_MAX * (7000 - 5000) + 5000; // randomized platinum ingot Price
	    float goldenmateriaPrice = (float) rand() / (float) RAND_MAX * (5500 - 3500) + 3500; // randomized golden materia price
	    float scarletitePrice = (float) rand() / (float) RAND_MAX * (12000 - 8000) + 8000; // randomized scarletite price
	    float adamantitePrice = (float) rand() / (float) RAND_MAX * (30000 - 15000) + 15000; // randomized adamantite price
	    float darkmatterPrice = (float) rand() / (float) RAND_MAX * (70000 - 40000) + 40000; // randomized dark matter price
	    float trapezohedronPrice= (float) rand() / (float) RAND_MAX * (90000 - 60000) + 60000; // randomized trapezohedron price
	    
	    	//Special items will never sold out
			if(random < 30 || random == 30){ //has a 30% chance of being sold out.
			phoenixDownPrice = 0;
	    }
	    	if (random < 30 || random == 30) { // has a 30% chance of being sold out.
				elixiressencePrice = 0;
			}
					if (random < 30 || random == 30) { // has a 30% chance of being sold out.
						goldenmateriaPrice = 0;
					}
						if(random < 30 || random == 30) { // has a 30% chance of being sold out.
							scarletitePrice = 0;
						}
							if (random < 30 || random == 30){ // has a 30% chance of being sold out.
								adamantitePrice = 0;
							}
								if (random < 30 || random == 30){ // has a 30% chance of being sold out.
									darkmatterPrice = 0;
								}
									if (random < 30 ){ // has a 30% chance of being sold out.
												trapezohedronPrice= 0;
											}
	    
	    printf("Shopkeeper: Welcome! How may I be of service?");
	    printf ("\n\n");
	    printf("Day %d\n" , *day);
	    printf("Gil: %.2f \n", *balance);
	    printf("Debt: %.2f\n", *debt);
	    printf("\t\t\t\t\t        Item       On Hand   Price");
	    printf("\n");
	    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
		printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
		
		printf("Note: If you chose to type 0, it will end the day");
		
			do { // this do loop repeats when user wants to sell items again & stops when there is no item anymore
			        		printf("Shopkeeper: Selling an item? Which one? \n");
			    			scanf("%d", &itemSell);
			    	
							if (itemSell == 1){	
			    				printf ("How many Phoenix Down do you wish to sell?\n");
			    				scanf("%d", &itemQuantity);
			    		
					    			if (*phoenixdown < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					                	system("pause");
					        		}
					        		else if (itemQuantity > *phoenixdown) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * phoenixDownPrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
						    			printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
										
						            	*phoenixdown -= itemQuantity; // equation for updating the inventory
						            	system("pause");
									}
							} // End of Phoenix Down Sell Segment
					
							else if (itemSell == 2){
				    			printf ("How many Elixir Essence do you wish to sell?\n");
				    			scanf("%d", &itemQuantity);
				    		
						    		if (*elixiressence < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					                	system("pause");
					        		}
					        		else if (itemQuantity > *elixiressence) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * elixiressencePrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
						            	*elixiressence -= itemQuantity; // equation for updating the inventory
						            	system("pause");
									}
							} // End of elixir essence Sell Segment
						
							else if (itemSell == 3)
				    		{
					    		printf ("How many Elixir Essence do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
					    			if (*platinumingot < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					                	system("pause");
					        		}
					        		else if (itemQuantity > *platinumingot) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * platinumingotPrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
						            	*platinumingot -= itemQuantity; // equation for updating the inventory
									}
							} // End of platinum ingot Sell Segment
					
							else if (itemSell == 4)
					    	{
					    		printf ("How many Golden Materia do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
						    		if (*goldenmateria < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					                	system("pause");
					        		}
					        		else if (itemQuantity > *goldenmateria) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * goldenmateriaPrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
						            	*goldenmateria -= itemQuantity; // equation for updating the inventory
									}
							} // End of golden materia Sell Segment
					
							else if (itemSell == 5)
					    	{
					    		printf ("How many Scarletite do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
						    		if (*scarletite < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					        			system("pause");
					        		}
					        		else if (itemQuantity > *scarletite) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * scarletitePrice;
					            		*balance += total;
										printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
						            	*scarletite -= itemQuantity; // equation for updating the inventory
									}
							} // End of scarletite Sell Segment
					
							else if (itemSell == 6)
				    		{
					    		printf ("How many Adamantite do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
						    		if (*adamantite < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					        			system("pause");
					        		}
					        		else if (itemQuantity > *adamantite) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * adamantitePrice;
					            		*balance += total;
										printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
										
						            	*adamantite -= itemQuantity; // equation for updating the inventory
									}
							} // End of adamantite Sell Segment
					
							else if (itemSell == 7)
					    	{
					    		printf ("How many Dark Matter do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
						    		if (*darkmatter < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					        			system("pause");
					        		}
					        		else if (itemQuantity > *adamantite) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * darkmatterPrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
										
						            	*darkmatter -= itemQuantity; // equation for updating the inventory
									}
							} // End of dark matter Sell Segment
					
							else if (itemSell == 8)
					    	{
					    		printf ("How many Trapezohedron do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
					    		if (*trapezohedron < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					        			system("pause");
					        		}
					        		else if (itemQuantity > *adamantite) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * trapezohedronPrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
										
						            	*trapezohedron -= itemQuantity; // equation for updating the inventory
									}
							} // End of trapezohedron Sell Segment
					} while (confirm == 'Y' || confirm == 'y'); // end of this do loop that repeats when user wants to sell items again & stops when there is no item anymore		
	    
		printf("Balance left: %.2f \n", *balance);
	    printf("Debt: %.2f\n", *debt);
	    printf("\n");
	    printf("\t\t\t\t\tPhoenix Down       %dx      (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   	printf("\t\t\t\t\tElixir Essence     %dx      (%.2f)\n", *elixiressence ,elixiressencePrice);
	    printf("\t\t\t\t\tPlatinum Ingot      %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    printf("\t\t\t\t\tGolden Materia       %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
		printf("\t\t\t\t\tScarletite          %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    printf("\t\t\t\t\tAdamantite      %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    printf("\t\t\t\t\tDark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
		printf("\t\t\t\t\tTrapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);    
	    printf("-----End of Day %d-----\n", *day); // updates of balance, inventories, and end of day;
	    
	    system("pause");
	}
	
void shoparch (int *phoenixdown, int *elixiressence, int *platinumingot,int *goldenmateria, 
	int *scarletite, int *adamantite, int *darkmatter,int *trapezohedron, float *balance, int *day, float *debt) // for archadian shop
{
	    int mon;
	    int random = rand() % 100 + 1;
	    int i;
	    
		time_t t = 0; // required to use srand
	    srand((unsigned) time(&t));
	    float phoenixDownPrice = (float) rand() / (float) RAND_MAX * (1200 - 500) + 500; // randomized phoenix down price
	    float elixiressencePrice = (float) rand() / (float) RAND_MAX * (2100 - 1500) + 1500; // randomized elixir essence price
	    float platinumingotPrice = (float) rand() / (float) RAND_MAX * (7000 - 5000) + 5000; // randomized platinum ingot Price
	    float goldenmateriaPrice = (float) rand() / (float) RAND_MAX * (5500 - 3500) + 3500; // randomized golden materia price
	    float scarletitePrice = (float) rand() / (float) RAND_MAX * (12000 - 8000) + 8000; // randomized scarletite price
	    float adamantitePrice = (float) rand() / (float) RAND_MAX * (30000 - 15000) + 15000; // randomized adamantite price
	    float darkmatterPrice = (float) rand() / (float) RAND_MAX * (70000 - 40000) + 40000; // randomized dark matter price
	    float trapezohedronPrice= (float) rand() / (float) RAND_MAX * (90000 - 60000) + 60000; // randomized trapezohedron price
	    
	    	//Special items will never sold out
			if(random < 30 || random == 30){ //has a 30% chance of being sold out.
			phoenixDownPrice = 0;
	    }
	    	if (random < 30 || random == 30) { // has a 30% chance of being sold out.
				elixiressencePrice = 0;
			}
					if (random < 30 || random == 30) { // has a 30% chance of being sold out.
						goldenmateriaPrice = 0;
					}
						if(random < 30 || random == 30) { // has a 30% chance of being sold out.
							scarletitePrice = 0;
						}
							if (random < 30 || random == 30){ // has a 30% chance of being sold out.
								adamantitePrice = 0;
							}
								if (random < 30 || random == 30){ // has a 30% chance of being sold out.
									darkmatterPrice = 0;
								}
									if (random < 30 ){ // has a 30% chance of being sold out.
												trapezohedronPrice= 0;
											}
	    
	    printf("Shopkeeper: Welcome! How may I be of service?");
	    printf ("\n");
	    printf("Day %d\n" , *day);
	    printf("Gil: %.2f \n", *balance);
	    printf("Debt: %.2f\n", *debt);
	    printf("\t\t\t\t\t    Item       On Hand    Price");
	    printf("\n");
	    printf("\t\t\t\t\tPhoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	    printf("\t\t\t\t\tElixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    printf("\t\t\t\t\tPlatinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    printf("\t\t\t\t\tGolden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    printf("\t\t\t\t\tScarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    printf("\t\t\t\t\tAdamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    printf("\t\t\t\t\tDark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
		printf("\t\t\t\t\tTrapezohedron    %dx     (%.2f)\n\n", *trapezohedron ,trapezohedronPrice);
		
		printf ("Note: If you try to sell even if you don't have an item in your inventory it will skip the day\n");
		printf ("so make sure you have atleast 1 in your inventory when selling.\n\n");
		
		printf("\t\t\t\t\t[1] Buy\n");
		printf("\t\t\t\t\t[2] Sell\n");
		printf("\t\t\t\t\t[3] Skip Day\n");
	    printf("Your Choice: ");
	    scanf("%d", &mon);
	    
	    switch (mon){
	    	case 1: archbuy (&*phoenixdown, &*elixiressence, &*platinumingot,&*goldenmateria, 
		 &*scarletite, &*adamantite, &*darkmatter, &*trapezohedron, &*balance, &*day, &*debt); break;
	    	case 2: sellarch (&*phoenixdown, &*elixiressence, &*platinumingot,&*goldenmateria, 
		 &*scarletite, &*adamantite, &*darkmatter, &*trapezohedron, &*balance, &*day, &*debt); break; 
	    	case 3: skip(&*day);break;
		}
	    
			    
}
	void cidbuy (int *phoenixdown, int *elixiressence, int *platinumingot,int *goldenmateria, 
		int *scarletite, int *adamantite, int *darkmatter,int *trapezohedron, float *balance, int *day, float *debt) // for buying items in cid's shop
{
		int itemOrder, itemQuantity; // variable for order type and desired quantity, respectively
	    char confirm, addOrder; // variables for confirming purchase and additional purchase, respectively
	    float total = 0.0; // variable for total cost of orders
	    int random = rand() % 100 + 1;
	    int i;
	    
	    // prices are different in buy and sell because of special items
	    time_t t = 0; // required to use srand
	    srand((unsigned) time(&t));
	    float phoenixDownPrice = (float) rand() / (float) RAND_MAX * (1200 - 500) + 500; // randomized phoenix down price
	    float elixiressencePrice = (float) rand() / (float) RAND_MAX * (2100 - 1500) + 1500; // randomized elixir essence price
	    float platinumingotPrice = (float) rand() / (float) RAND_MAX * (7000 - 5000) + 5000; // randomized platinum ingot Price
	    float goldenmateriaPrice = (float) rand() / (float) RAND_MAX * (5000 - 3000) + 3000; // SPECIAL ITEM randomized golden materia price
	    float scarletitePrice = (float) rand() / (float) RAND_MAX * (12000 - 8000) + 8000; // randomized scarletite price
	    float adamantitePrice = (float) rand() / (float) RAND_MAX * (30000 - 15000) + 15000; // randomized adamantite price
	    float darkmatterPrice = (float) rand() / (float) RAND_MAX * (70000 - 40000) + 40000; // randomized dark matter price
	    float trapezohedronPrice= (float) rand() / (float) RAND_MAX * (90000 - 60000) + 60000; // randomized dark matter price
	    
	        	//Special items will never sold out
			if(random < 30 || random == 30){ //has a 30% chance of being sold out.
			phoenixDownPrice = 0;
	    }
	    	if (random < 30 || random == 30) { // has a 30% chance of being sold out.
				elixiressencePrice = 0;
			}
				if(random < 30 || random == 30){ // has a 30% chance of being sold out.
					platinumingotPrice = 0;
				}
						if(random < 30 || random == 30) { // has a 30% chance of being sold out.
							scarletitePrice = 0;
						}
							if (random < 30 || random == 30){ // has a 30% chance of being sold out.
								adamantitePrice = 0;
							}
								if (random < 30 || random == 30){ // has a 30% chance of being sold out.
									darkmatterPrice = 0;
								}
									if (random < 30 ){ // has a 30% chance of being sold out.
												trapezohedronPrice= 0;
											}
	    
	    printf("Shopkeeper: Welcome! How may I be of service?");
	    printf ("\n\n");
	    printf("Day %d\n" , *day);
	    printf("Gil: %.2f \n", *balance);
	    printf("Debt: %.2f\n", *debt);
	    printf("\t\t\t\t\t       Item        On Hand    Price");
	    printf("\n");
	    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
		printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
	
	    printf("Note: If you can no longer afford an item, the day will proceed\n\n");
	    
	    do { // this do loop repeats when user wants to order items again & stops when balance is insufficient
	        printf("Shopkeeper: Buying an item? Which one? \n");
	        scanf("%d", &itemOrder);
	        
	        // this segment is for thePhoenix Down item order
	        if(itemOrder == 1) {
	            printf("How many Phoenix Down do you wish to buy?\n");
	            scanf("%d", &itemQuantity);
	            
	            while (itemQuantity * phoenixDownPrice > *balance) { // error handling if balance is not enough
	                printf("Insufficient balance. Only buy what you can afford.\n");
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * phoenixDownPrice;
	            *balance -= total;
	                
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	                
	            printf("Confirm Order? (Y/N) \n");
	            scanf("%c", &confirm); // throughout the program, i placed 2 scanf for char
	            scanf("%c", &confirm); // because it only works if 2 are present instead of 1 (only for char)
	                                   
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *phoenixdown += itemQuantity; // equation for updating the inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);          
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of Phoenix Down segment
	        
	        // this segment is for the Elixir Essence item
	        else if(itemOrder == 2) {
	            printf("How many Elixir Essence do you wish to buy?\n");
	            scanf("%d", &itemQuantity);
	            
	            while (itemQuantity * elixiressencePrice > *balance) {
	                printf("Insufficient balance. Only buy what you can afford.\n");  // error handling if
	                scanf("%d", &itemQuantity);                                   // balance is not enough
	            }
	            
	            total = itemQuantity * elixiressencePrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs for char since it won't work if only 1 is placed
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *elixiressence += itemQuantity; // equation for updating the elixir essence inventory
	
	    			
					printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);   
	                
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of elixir essence segment
	        
	        // this segment is for the platinum ingot order
	        else if(itemOrder == 3) {
	            printf("How many Platinum Ingot do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * platinumingotPrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * platinumingotPrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *platinumingot += itemQuantity; // equation for updating the 	 inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);  
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of platinum ingot segment
	               
				    // this segment is for the golden materia order
	        else if(itemOrder == 4) {
	            printf("How many Golden Materia do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * goldenmateriaPrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * goldenmateriaPrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *goldenmateria += itemQuantity; // equation for updating the 	 inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);  
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of golden materia segment
	        
	        // this segment is for the scarletite order
	        else if(itemOrder == 5) {
	            printf("How many Scarletite do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * scarletitePrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * scarletitePrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *scarletite += itemQuantity; // equation for updating the 	 inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);  
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of scarletite segment
	        
	        // this segment is for the adamantite order
	        else if(itemOrder == 6) {
	            printf("How many Adamantite do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * adamantitePrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * adamantitePrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *adamantite += itemQuantity; // equation for updating the 	 inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);  
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of adamantite segment
	        
	                // this segment is for the dark matter order
	        	else if(itemOrder == 7) {
	            printf("How many Dark Matter do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * darkmatterPrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * darkmatterPrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *darkmatter += itemQuantity; // equation for updating the 	 inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);  
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of dark matter segment
	        
	            // this segment is for the trapezohedron order
	        	else if(itemOrder == 8) {
	            printf("How many Trapezohedron do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * trapezohedronPrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * trapezohedronPrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *trapezohedron += itemQuantity; // equation for updating the 	 inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);  
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of trapezohedron segment
	        
	        else if(itemOrder > 8) { // error handling wherein program only allows user to choose between 1-8
	            printf("Choose a number between 1-8 only.\n");
	        }
	                // if balance is < the prices of items, user will not be able to buy again
	        if(*balance < phoenixDownPrice && (*balance < elixiressencePrice && *balance < platinumingotPrice && *balance < goldenmateriaPrice &&
			 *balance < goldenmateriaPrice && *balance < scarletitePrice && *balance < adamantitePrice && *balance < darkmatterPrice && *balance < trapezohedronPrice )){
	            printf("Cannot buy any more items. Balance is insufficient.\n\n");
	        }        
	        // however, if balance is > the prices of items, user is allowed to buy over & over again
	        else if (*balance > phoenixDownPrice || *balance > elixiressencePrice || *balance > platinumingotPrice|| *balance > goldenmateriaPrice
				|| *balance > scarletitePrice || *balance > adamantitePrice || *balance > darkmatterPrice || *balance > trapezohedronPrice){
	            printf("Do you wish to order more items? (Y/N)\n");
	            scanf("%c", &addOrder);
	        }                          // 2 scanf here to make the char work on my compiler
	        
			scanf("%c", &addOrder);
	    } while(addOrder == 'Y' || addOrder == 'y'); // this is the end of the do while loop, repeats once user
	                                                 // wants to order again under certain conditions
	    printf("-----End of Day %d-----\n", *day);   // %d refers to i in the main function, it updates the nth day
	    printf("=======================\n");
	    
	    
}
	
void sellcid (int *phoenixdown, int *elixiressence, int *platinumingot,int *goldenmateria, 
	int *scarletite, int *adamantite, int *darkmatter,int *trapezohedron, float *balance, int *day, float *debt)// for selling items in cid's shop
{
		int i, itemSell, itemQuantity; // variables for the loop and the user's guess in selling, respectively
		float total = 0.0; // variable for total
		char confirm;
		int random = rand() % 100 + 1;
		
		
		time_t t = 0; // required to use srand
	    srand((unsigned) time(&t));
	    float phoenixDownPrice = (float) rand() / (float) RAND_MAX * (1200 - 500) + 500; // randomized phoenix down price
	    float elixiressencePrice = (float) rand() / (float) RAND_MAX * (2100 - 1500) + 1500; // randomized elixir essence price
	    float platinumingotPrice = (float) rand() / (float) RAND_MAX * (7000 - 5000) + 5000; // randomized platinum ingot Price
	    float goldenmateriaPrice = (float) rand() / (float) RAND_MAX * (5500 - 3500) + 3500; // randomized golden materia price
	    float scarletitePrice = (float) rand() / (float) RAND_MAX * (12000 - 8000) + 8000; // randomized scarletite price
	    float adamantitePrice = (float) rand() / (float) RAND_MAX * (30000 - 15000) + 15000; // randomized adamantite price
	    float darkmatterPrice = (float) rand() / (float) RAND_MAX * (70000 - 40000) + 40000; // randomized dark matter price
	    float trapezohedronPrice= (float) rand() / (float) RAND_MAX * (90000 - 60000) + 60000; // randomized trapezohedron price
	    
	    //Special items will never sold out
			if(random < 30 || random == 30){ //has a 30% chance of being sold out.
			phoenixDownPrice = 0;
	    }
	    	if (random < 30 || random == 30) { // has a 30% chance of being sold out.
				elixiressencePrice = 0;
			}
				if(random < 30 || random == 30){ // has a 30% chance of being sold out.
					platinumingotPrice = 0;
				}
						if(random < 30 || random == 30) { // has a 30% chance of being sold out.
							scarletitePrice = 0;
						}
							if (random < 30 || random == 30){ // has a 30% chance of being sold out.
								adamantitePrice = 0;
							}
								if (random < 30 || random == 30){ // has a 30% chance of being sold out.
									darkmatterPrice = 0;
								}
									if (random < 30 ){ // has a 30% chance of being sold out.
												trapezohedronPrice= 0;
											}
	    
	    printf("Shopkeeper: Welcome! How may I be of service?");
	    printf ("\n\n");
	    printf("Day %d\n" , *day);
	    printf("Gil: %.2f \n", *balance);
	    printf("Debt: %.2f\n", *debt);
	    printf("\t\t\t\t\t        Item       On Hand   Price");
	    printf("\n");
	    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
		printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
		
		printf("Note: If you chose to type 0, it will end the day");
		
			do { // this do loop repeats when user wants to sell items again & stops when there is no item anymore
			        		printf("Shopkeeper: Selling an item? Which one? \n");
			    			scanf("%d", &itemSell);
			    	
							if (itemSell == 1){	
			    				printf ("How many Phoenix Down do you wish to sell?\n");
			    				scanf("%d", &itemQuantity);
			    		
					    			if (*phoenixdown < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					                	system("pause");
					        		}
					        		else if (itemQuantity > *phoenixdown) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * phoenixDownPrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
						    			printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
										
						            	*phoenixdown -= itemQuantity; // equation for updating the inventory
						            	system("pause");
									}
							} // End of Phoenix Down Sell Segment
					
							else if (itemSell == 2){
				    			printf ("How many Elixir Essence do you wish to sell?\n");
				    			scanf("%d", &itemQuantity);
				    		
						    		if (*elixiressence < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					                	system("pause");
					        		}
					        		else if (itemQuantity > *elixiressence) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * elixiressencePrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
						            	*elixiressence -= itemQuantity; // equation for updating the inventory
						            	system("pause");
									}
							} // End of elixir essence Sell Segment
						
							else if (itemSell == 3)
				    		{
					    		printf ("How many Elixir Essence do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
					    			if (*platinumingot < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					                	system("pause");
					        		}
					        		else if (itemQuantity > *platinumingot) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * platinumingotPrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
						            	*platinumingot -= itemQuantity; // equation for updating the inventory
									}
							} // End of platinum ingot Sell Segment
					
							else if (itemSell == 4)
					    	{
					    		printf ("How many Golden Materia do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
						    		if (*goldenmateria < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					                	system("pause");
					        		}
					        		else if (itemQuantity > *goldenmateria) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * goldenmateriaPrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
						            	*goldenmateria -= itemQuantity; // equation for updating the inventory
									}
							} // End of golden materia Sell Segment
					
							else if (itemSell == 5)
					    	{
					    		printf ("How many Scarletite do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
						    		if (*scarletite < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					        			system("pause");
					        		}
					        		else if (itemQuantity > *scarletite) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * scarletitePrice;
					            		*balance += total;
										printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
						            	*scarletite -= itemQuantity; // equation for updating the inventory
									}
							} // End of scarletite Sell Segment
					
							else if (itemSell == 6)
				    		{
					    		printf ("How many Adamantite do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
						    		if (*adamantite < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					        			system("pause");
					        		}
					        		else if (itemQuantity > *adamantite) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * adamantitePrice;
					            		*balance += total;
										printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
										
						            	*adamantite -= itemQuantity; // equation for updating the inventory
									}
							} // End of adamantite Sell Segment
					
							else if (itemSell == 7)
					    	{
					    		printf ("How many Dark Matter do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
						    		if (*darkmatter < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					        			system("pause");
					        		}
					        		else if (itemQuantity > *adamantite) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * darkmatterPrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
										
						            	*darkmatter -= itemQuantity; // equation for updating the inventory
									}
							} // End of dark matter Sell Segment
					
							else if (itemSell == 8)
					    	{
					    		printf ("How many Trapezohedron do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
					    		if (*trapezohedron < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					        			system("pause");
					        		}
					        		else if (itemQuantity > *adamantite) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * trapezohedronPrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
										
						            	*trapezohedron -= itemQuantity; // equation for updating the inventory
									}
							} // End of trapezohedron Sell Segment
					} while (confirm == 'Y' || confirm == 'y'); // end of this do loop that repeats when user wants to sell items again & stops when there is no item anymore		
	    
		printf("Balance left: %.2f \n", *balance);
	    printf("Debt: %.2f\n", *debt);
	    printf("\n");
	    printf("\t\t\t\t\tPhoenix Down       %dx      (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   	printf("\t\t\t\t\tElixir Essence     %dx      (%.2f)\n", *elixiressence ,elixiressencePrice);
	    printf("\t\t\t\t\tPlatinum Ingot      %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    printf("\t\t\t\t\tGolden Materia       %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
		printf("\t\t\t\t\tScarletite          %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    printf("\t\t\t\t\tAdamantite      %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    printf("\t\t\t\t\tDark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
		printf("\t\t\t\t\tTrapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);    
	    printf("-----End of Day %d-----\n", *day); // updates of balance, inventories, and end of day;
	    
	    system("pause");
	}
	
void shopcid (int *phoenixdown, int *elixiressence, int *platinumingot,int *goldenmateria, 
		int *scarletite, int *adamantite, int *darkmatter,int *trapezohedron, float *balance, int *day, float *debt) // for cid's shop
{
	    int mon;
	    int random = rand() % 100 + 1;
	    int i;
	    
		time_t t = 0; // required to use srand
	    srand((unsigned) time(&t));
	    float phoenixDownPrice = (float) rand() / (float) RAND_MAX * (1200 - 500) + 500; // randomized phoenix down price
	    float elixiressencePrice = (float) rand() / (float) RAND_MAX * (2100 - 1500) + 1500; // randomized elixir essence price
	    float platinumingotPrice = (float) rand() / (float) RAND_MAX * (7000 - 5000) + 5000; // randomized platinum ingot Price
	    float goldenmateriaPrice = (float) rand() / (float) RAND_MAX * (5500 - 3500) + 3500; // randomized golden materia price
	    float scarletitePrice = (float) rand() / (float) RAND_MAX * (12000 - 8000) + 8000; // randomized scarletite price
	    float adamantitePrice = (float) rand() / (float) RAND_MAX * (30000 - 15000) + 15000; // randomized adamantite price
	    float darkmatterPrice = (float) rand() / (float) RAND_MAX * (70000 - 40000) + 40000; // randomized dark matter price
	    float trapezohedronPrice= (float) rand() / (float) RAND_MAX * (90000 - 60000) + 60000; // randomized trapezohedron price
	    
	    //Special items will never sold out
			if(random < 30 || random == 30){ //has a 30% chance of being sold out.
			phoenixDownPrice = 0;
	    }
	    	if (random < 30 || random == 30) { // has a 30% chance of being sold out.
				elixiressencePrice = 0;
			}
				if(random < 30 || random == 30){ // has a 30% chance of being sold out.
					platinumingotPrice = 0;
				}
						if(random < 30 || random == 30) { // has a 30% chance of being sold out.
							scarletitePrice = 0;
						}
							if (random < 30 || random == 30){ // has a 30% chance of being sold out.
								adamantitePrice = 0;
							}
								if (random < 30 || random == 30){ // has a 30% chance of being sold out.
									darkmatterPrice = 0;
								}
									if (random < 30 ){ // has a 30% chance of being sold out.
												trapezohedronPrice= 0;
											}
	    
	    printf("Shopkeeper: Welcome! How may I be of service?");
	    printf ("\n");
	    printf("Day %d\n" , *day);
	    printf("Gil: %.2f \n", *balance);
	    printf("Debt: %.2f\n", *debt);
	    printf("\t\t\t\t\t    Item       On Hand    Price");
	    printf("\n");
	    printf("\t\t\t\t\tPhoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	    printf("\t\t\t\t\tElixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    printf("\t\t\t\t\tPlatinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    printf("\t\t\t\t\tGolden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    printf("\t\t\t\t\tScarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    printf("\t\t\t\t\tAdamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    printf("\t\t\t\t\tDark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
		printf("\t\t\t\t\tTrapezohedron    %dx     (%.2f)\n\n", *trapezohedron ,trapezohedronPrice);
		
		printf ("Note: If you try to sell even if you don't have an item in your inventory it will skip the day\n");
		printf ("so make sure you have atleast 1 in your inventory when selling.\n\n");
		
		printf("\t\t\t\t\t[1] Buy\n");
		printf("\t\t\t\t\t[2] Sell\n");
		printf("\t\t\t\t\t[3] Skip Day\n");
	    printf("Your Choice: ");
	    scanf("%d", &mon);
	    
	    switch (mon){
	    	case 1: cidbuy (&*phoenixdown, &*elixiressence, &*platinumingot,&*goldenmateria, 
		 &*scarletite, &*adamantite, &*darkmatter, &*trapezohedron, &*balance, &*day, &*debt); break;
	    	case 2: sellcid (&*phoenixdown, &*elixiressence, &*platinumingot,&*goldenmateria, 
		 &*scarletite, &*adamantite, &*darkmatter, &*trapezohedron, &*balance, &*day, &*debt); break; 
	    	case 3: skip(&*day);break;
		}
	    
			    
}
void gaianbuy (int *phoenixdown, int *elixiressence, int *platinumingot,int *goldenmateria, 
	int *scarletite, int *adamantite, int *darkmatter,int *trapezohedron, float *balance, int *day, float *debt) // for buying items in gaian shop
{
		int itemOrder, itemQuantity; // variable for order type and desired quantity, respectively
	    char confirm, addOrder; // variables for confirming purchase and additional purchase, respectively
	    float total = 0.0; // variable for total cost of orders
	    int random = rand() % 100 + 1;
	    int i;
	    
	    // prices are different in buy and sell because of special items
	    time_t t = 0; // required to use srand
	    srand((unsigned) time(&t));
	    float phoenixDownPrice = (float) rand() / (float) RAND_MAX * (1200 - 500) + 500; // randomized phoenix down price
	    float elixiressencePrice = (float) rand() / (float) RAND_MAX * (2100 - 1500) + 1500; // randomized elixir essence price
	    float platinumingotPrice = (float) rand() / (float) RAND_MAX * (7000 - 5000) + 5000; // randomized platinum ingot Price
	    float goldenmateriaPrice = (float) rand() / (float) RAND_MAX * (5500 - 3500) + 3500; // randomized golden materia price
	    float scarletitePrice = (float) rand() / (float) RAND_MAX * (10000 - 5000) + 5000; // SPECIAL ITEM randomized scarletite price
	    float adamantitePrice = (float) rand() / (float) RAND_MAX * (30000 - 15000) + 15000; // randomized adamantite price
	    float darkmatterPrice = (float) rand() / (float) RAND_MAX * (70000 - 40000) + 40000; // randomized dark matter price
	    float trapezohedronPrice= (float) rand() / (float) RAND_MAX * (90000 - 60000) + 60000; // randomized dark matter price
	    
	        	//Special items will never sold out
			if(random < 30 || random == 30){ //has a 30% chance of being sold out.
			phoenixDownPrice = 0;
	    }
	    	if (random < 30 || random == 30) { // has a 30% chance of being sold out.
				elixiressencePrice = 0;
			}
				if(random < 30 || random == 30){ // has a 30% chance of being sold out.
					platinumingotPrice = 0;
				}
					if (random < 30 || random == 30) { // has a 30% chance of being sold out.
						goldenmateriaPrice = 0;
					}
							if (random < 30 || random == 30){ // has a 30% chance of being sold out.
								adamantitePrice = 0;
							}
								if (random < 30 || random == 30){ // has a 30% chance of being sold out.
									darkmatterPrice = 0;
								}
									if (random < 30 ){ // has a 30% chance of being sold out.
												trapezohedronPrice= 0;
											}
	    
	    printf("Shopkeeper: Welcome! How may I be of service?");
	    printf ("\n\n");
	    printf("Day %d\n" , *day);
	    printf("Gil: %.2f \n", *balance);
	    printf("Debt: %.2f\n", *debt);
	    printf("\t\t\t\t\t       Item        On Hand    Price");
	    printf("\n");
	    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
		printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
	
	    printf("Note: If you can no longer afford an item, the day will proceed\n\n");
	    
	    do { // this do loop repeats when user wants to order items again & stops when balance is insufficient
	        printf("Shopkeeper: Buying an item? Which one? \n");
	        scanf("%d", &itemOrder);
	        
	        // this segment is for the Phoenix Down item order
	        if(itemOrder == 1) {
	            printf("How many Phoenix Down do you wish to buy?\n");
	            scanf("%d", &itemQuantity);
	            
	            while (itemQuantity * phoenixDownPrice > *balance) { // error handling if balance is not enough
	                printf("Insufficient balance. Only buy what you can afford.\n");
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * phoenixDownPrice;
	            *balance -= total;
	                
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	                
	            printf("Confirm Order? (Y/N) \n");
	            scanf("%c", &confirm); // throughout the program, i placed 2 scanf for char
	            scanf("%c", &confirm); // because it only works if 2 are present instead of 1 (only for char)
	                                   
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *phoenixdown += itemQuantity; // equation for updating the inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);          
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of Phoenix Down segment
	        
	        // this segment is for the Elixir Essence item
	        else if(itemOrder == 2) {
	            printf("How many Elixir Essence do you wish to buy?\n");
	            scanf("%d", &itemQuantity);
	            
	            while (itemQuantity * elixiressencePrice > *balance) {
	                printf("Insufficient balance. Only buy what you can afford.\n");  // error handling if
	                scanf("%d", &itemQuantity);                                   // balance is not enough
	            }
	            
	            total = itemQuantity * elixiressencePrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs for char since it won't work if only 1 is placed
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *elixiressence += itemQuantity; // equation for updating the elixir essence inventory
	
	    			
					printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);  
	                
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of elixir essence segment
	        
	        // this segment is for the platinum ingot order
	        else if(itemOrder == 3) {
	            printf("How many Platinum Ingot do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * platinumingotPrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * platinumingotPrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *platinumingot += itemQuantity; // equation for updating the 	 inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);  
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of platinum ingot segment
	               
				    // this segment is for the golden materia order
	        else if(itemOrder == 4) {
	            printf("How many Golden Materia do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * goldenmateriaPrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * goldenmateriaPrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *goldenmateria += itemQuantity; // equation for updating the 	 inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);  
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of golden materia segment
	        
	        // this segment is for the scarletite order
	        else if(itemOrder == 5) {
	            printf("How many Scarletite do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * scarletitePrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * scarletitePrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *scarletite += itemQuantity; // equation for updating the 	 inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);  
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of scarletite segment
	        
	        // this segment is for the adamantite order
	        else if(itemOrder == 6) {
	            printf("How many Adamantite do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * adamantitePrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * adamantitePrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *adamantite += itemQuantity; // equation for updating the 	 inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);  
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of adamantite segment
	        
	                // this segment is for the dark matter order
	        	else if(itemOrder == 7) {
	            printf("How many Dark Matter do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * darkmatterPrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * darkmatterPrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *darkmatter += itemQuantity; // equation for updating the 	 inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);  
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of dark matter segment
	        
	            // this segment is for the trapezohedron order
	        	else if(itemOrder == 8) {
	            printf("How many Trapezohedron do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * trapezohedronPrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * trapezohedronPrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *trapezohedron += itemQuantity; // equation for updating the 	 inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);  
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of trapezohedron segment
	        
	        else if(itemOrder > 8) { // error handling wherein program only allows user to choose between 1-8
	            printf("Choose a number between 1-8 only.\n");
	        }
	                // if balance is < the prices of items, user will not be able to buy again
	        if(*balance < phoenixDownPrice && (*balance < elixiressencePrice && *balance < platinumingotPrice && *balance < goldenmateriaPrice &&
			 *balance < goldenmateriaPrice && *balance < scarletitePrice && *balance < adamantitePrice && *balance < darkmatterPrice && *balance < trapezohedronPrice )){
	            printf("Cannot buy any more items. Balance is insufficient.\n\n");
	        }        
	        // however, if balance is > the prices of items, user is allowed to buy over & over again
	        else if (*balance > phoenixDownPrice || *balance > elixiressencePrice || *balance > platinumingotPrice|| *balance > goldenmateriaPrice
				|| *balance > scarletitePrice || *balance > adamantitePrice || *balance > darkmatterPrice || *balance > trapezohedronPrice){
	            printf("Do you wish to order more items? (Y/N)\n");
	            scanf("%c", &addOrder);
	        }                          // 2 scanf here to make the char work on my compiler
	        
			scanf("%c", &addOrder);
	    } while(addOrder == 'Y' || addOrder == 'y'); // this is the end of the do while loop, repeats once user
	                                                 // wants to order again under certain conditions
	    printf("-----End of Day %d-----\n", *day);   // %d refers to i in the main function, it updates the nth day
	    printf("=======================\n");
	    
	    
}
	
void sellgaian (int *phoenixdown, int *elixiressence, int *platinumingot,int *goldenmateria, 
		int *scarletite, int *adamantite, int *darkmatter,int *trapezohedron, float *balance, int *day, float *debt) //for selling items in gaian shop
{
		int i, itemSell, itemQuantity; // variables for the loop and the user's guess in selling, respectively
		float total = 0.0; // variable for total
		char confirm;
		int random = rand() % 100 + 1;
		
		time_t t = 0; // required to use srand
	    srand((unsigned) time(&t));
	    float phoenixDownPrice = (float) rand() / (float) RAND_MAX * (1200 - 500) + 500; // randomized phoenix down price
	    float elixiressencePrice = (float) rand() / (float) RAND_MAX * (2100 - 1500) + 1500; // randomized elixir essence price
	    float platinumingotPrice = (float) rand() / (float) RAND_MAX * (7000 - 5000) + 5000; // randomized platinum ingot Price
	    float goldenmateriaPrice = (float) rand() / (float) RAND_MAX * (5500 - 3500) + 3500; // randomized golden materia price
	    float scarletitePrice = (float) rand() / (float) RAND_MAX * (12000 - 8000) + 8000; // randomized scarletite price
	    float adamantitePrice = (float) rand() / (float) RAND_MAX * (30000 - 15000) + 15000; // randomized adamantite price
	    float darkmatterPrice = (float) rand() / (float) RAND_MAX * (70000 - 40000) + 40000; // randomized dark matter price
	    float trapezohedronPrice= (float) rand() / (float) RAND_MAX * (90000 - 60000) + 60000; // randomized trapezohedron price
	    
	            	//Special items will never sold out
			if(random < 30 || random == 30){ //has a 30% chance of being sold out.
			phoenixDownPrice = 0;
	    }
	    	if (random < 30 || random == 30) { // has a 30% chance of being sold out.
				elixiressencePrice = 0;
			}
				if(random < 30 || random == 30){ // has a 30% chance of being sold out.
					platinumingotPrice = 0;
				}
					if (random < 30 || random == 30) { // has a 30% chance of being sold out.
						goldenmateriaPrice = 0;
					}
							if (random < 30 || random == 30){ // has a 30% chance of being sold out.
								adamantitePrice = 0;
							}
								if (random < 30 || random == 30){ // has a 30% chance of being sold out.
									darkmatterPrice = 0;
								}
									if (random < 30 ){ // has a 30% chance of being sold out.
												trapezohedronPrice= 0;
											}
	    
	    printf("Shopkeeper: Welcome! How may I be of service?");
	    printf ("\n\n");
	    printf("Day %d\n" , *day);
	    printf("Gil: %.2f \n", *balance);
	    printf("Debt: %.2f\n", *debt);
	    printf("\t\t\t\t\t        Item       On Hand   Price");
	    printf("\n");
	    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
		printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
		
		printf("Note: If you chose to type 0, it will end the day");
		
			do { // this do loop repeats when user wants to sell items again & stops when there is no item anymore
			        		printf("Shopkeeper: Selling an item? Which one? \n");
			    			scanf("%d", &itemSell);
			    	
							if (itemSell == 1){	
			    				printf ("How many Phoenix Down do you wish to sell?\n");
			    				scanf("%d", &itemQuantity);
			    		
					    			if (*phoenixdown < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					                	system("pause");
					        		}
					        		else if (itemQuantity > *phoenixdown) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * phoenixDownPrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
						    			printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
										
						            	*phoenixdown -= itemQuantity; // equation for updating the inventory
						            	system("pause");
									}
							} // End of Phoenix Down Sell Segment
					
							else if (itemSell == 2){
				    			printf ("How many Elixir Essence do you wish to sell?\n");
				    			scanf("%d", &itemQuantity);
				    		
						    		if (*elixiressence < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					                	system("pause");
					        		}
					        		else if (itemQuantity > *elixiressence) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * elixiressencePrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
						            	*elixiressence -= itemQuantity; // equation for updating the inventory
						            	system("pause");
									}
							} // End of elixir essence Sell Segment
						
							else if (itemSell == 3)
				    		{
					    		printf ("How many Elixir Essence do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
					    			if (*platinumingot < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					                	system("pause");
					        		}
					        		else if (itemQuantity > *platinumingot) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * platinumingotPrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
						            	*platinumingot -= itemQuantity; // equation for updating the inventory
									}
							} // End of platinum ingot Sell Segment
					
							else if (itemSell == 4)
					    	{
					    		printf ("How many Golden Materia do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
						    		if (*goldenmateria < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					                	system("pause");
					        		}
					        		else if (itemQuantity > *goldenmateria) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * goldenmateriaPrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
						            	*goldenmateria -= itemQuantity; // equation for updating the inventory
									}
							} // End of golden materia Sell Segment
					
							else if (itemSell == 5)
					    	{
					    		printf ("How many Scarletite do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
						    		if (*scarletite < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					        			system("pause");
					        		}
					        		else if (itemQuantity > *scarletite) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * scarletitePrice;
					            		*balance += total;
										printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
						            	*scarletite -= itemQuantity; // equation for updating the inventory
									}
							} // End of scarletite Sell Segment
					
							else if (itemSell == 6)
				    		{
					    		printf ("How many Adamantite do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
						    		if (*adamantite < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					        			system("pause");
					        		}
					        		else if (itemQuantity > *adamantite) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * adamantitePrice;
					            		*balance += total;
										printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
										
						            	*adamantite -= itemQuantity; // equation for updating the inventory
									}
							} // End of adamantite Sell Segment
					
							else if (itemSell == 7)
					    	{
					    		printf ("How many Dark Matter do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
						    		if (*darkmatter < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					        			system("pause");
					        		}
					        		else if (itemQuantity > *adamantite) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * darkmatterPrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
										
						            	*darkmatter -= itemQuantity; // equation for updating the inventory
									}
							} // End of dark matter Sell Segment
					
							else if (itemSell == 8)
					    	{
					    		printf ("How many Trapezohedron do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
					    		if (*trapezohedron < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					        			system("pause");
					        		}
					        		else if (itemQuantity > *adamantite) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * trapezohedronPrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
										
						            	*trapezohedron -= itemQuantity; // equation for updating the inventory
									}
							} // End of trapezohedron Sell Segment
					} while (confirm == 'Y' || confirm == 'y'); // end of this do loop that repeats when user wants to sell items again & stops when there is no item anymore		
	    
		printf("Balance left: %.2f \n", *balance);
	    printf("Debt: %.2f\n", *debt);
	    printf("\n");
	    printf("\t\t\t\t\tPhoenix Down       %dx      (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   	printf("\t\t\t\t\tElixir Essence     %dx      (%.2f)\n", *elixiressence ,elixiressencePrice);
	    printf("\t\t\t\t\tPlatinum Ingot      %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    printf("\t\t\t\t\tGolden Materia       %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
		printf("\t\t\t\t\tScarletite          %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    printf("\t\t\t\t\tAdamantite      %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    printf("\t\t\t\t\tDark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
		printf("\t\t\t\t\tTrapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);    
	    printf("-----End of Day %d-----\n", *day); // updates of balance, inventories, and end of day;
	    
	    system("pause");
	}
	
void shopgaian (int *phoenixdown, int *elixiressence, int *platinumingot,int *goldenmateria, 
	int *scarletite, int *adamantite, int *darkmatter,int *trapezohedron, float *balance, int *day, float *debt) // for gaian shop
{
	    int mon;
	    int random = rand() % 100 + 1;
	    int i;
	    
	    
		time_t t = 0; // required to use srand
	    srand((unsigned) time(&t));
	    float phoenixDownPrice = (float) rand() / (float) RAND_MAX * (1200 - 500) + 500; // randomized phoenix down price
	    float elixiressencePrice = (float) rand() / (float) RAND_MAX * (2100 - 1500) + 1500; // randomized elixir essence price
	    float platinumingotPrice = (float) rand() / (float) RAND_MAX * (7000 - 5000) + 5000; // randomized platinum ingot Price
	    float goldenmateriaPrice = (float) rand() / (float) RAND_MAX * (5500 - 3500) + 3500; // randomized golden materia price
	    float scarletitePrice = (float) rand() / (float) RAND_MAX * (12000 - 8000) + 8000; // randomized scarletite price
	    float adamantitePrice = (float) rand() / (float) RAND_MAX * (30000 - 15000) + 15000; // randomized adamantite price
	    float darkmatterPrice = (float) rand() / (float) RAND_MAX * (70000 - 40000) + 40000; // randomized dark matter price
	    float trapezohedronPrice= (float) rand() / (float) RAND_MAX * (90000 - 60000) + 60000; // randomized trapezohedron price
	    
	            	//Special items will never sold out
			if(random < 30 || random == 30){ //has a 30% chance of being sold out.
			phoenixDownPrice = 0;
	    }
	    	if (random < 30 || random == 30) { // has a 30% chance of being sold out.
				elixiressencePrice = 0;
			}
				if(random < 30 || random == 30){ // has a 30% chance of being sold out.
					platinumingotPrice = 0;
				}
					if (random < 30 || random == 30) { // has a 30% chance of being sold out.
						goldenmateriaPrice = 0;
					}
							if (random < 30 || random == 30){ // has a 30% chance of being sold out.
								adamantitePrice = 0;
							}
								if (random < 30 || random == 30){ // has a 30% chance of being sold out.
									darkmatterPrice = 0;
								}
									if (random < 30 ){ // has a 30% chance of being sold out.
												trapezohedronPrice= 0;
											}
	    
	    printf("Shopkeeper: Welcome! How may I be of service?");
	    printf ("\n");
	    printf("Day %d\n" , *day);
	    printf("Gil: %.2f \n", *balance);
	    printf("Debt: %.2f\n", *debt);
	    printf("\t\t\t\t\t    Item       On Hand    Price");
	    printf("\n");
	    printf("\t\t\t\t\tPhoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	    printf("\t\t\t\t\tElixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    printf("\t\t\t\t\tPlatinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    printf("\t\t\t\t\tGolden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    printf("\t\t\t\t\tScarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    printf("\t\t\t\t\tAdamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    printf("\t\t\t\t\tDark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
		printf("\t\t\t\t\tTrapezohedron    %dx     (%.2f)\n\n", *trapezohedron ,trapezohedronPrice);
		
		printf ("Note: If you try to sell even if you don't have an item in your inventory it will skip the day\n");
		printf ("so make sure you have atleast 1 in your inventory when selling.\n\n");
		
		printf("\t\t\t\t\t[1] Buy\n");
		printf("\t\t\t\t\t[2] Sell\n");
		printf("\t\t\t\t\t[3] Skip Day\n");
	    printf("Your Choice: ");
	    scanf("%d", &mon);
	    
	    switch (mon){
	    	case 1: gaianbuy (&*phoenixdown, &*elixiressence, &*platinumingot,&*goldenmateria, 
		 &*scarletite, &*adamantite, &*darkmatter, &*trapezohedron, &*balance, &*day, &*debt); break;
	    	case 2: sellgaian (&*phoenixdown, &*elixiressence, &*platinumingot,&*goldenmateria, 
		 &*scarletite, &*adamantite, &*darkmatter, &*trapezohedron, &*balance, &*day, &*debt); break; 
	    	case 3: skip(&*day);break;
		}
	    
			    
}
	
void richbuy (int *phoenixdown, int *elixiressence, int *platinumingot,int *goldenmateria, 
	int *scarletite, int *adamantite, int *darkmatter,int *trapezohedron, float *balance, int *day, float *debt) // for buying items in riches and minerals shop
{
		int itemOrder, itemQuantity; // variable for order type and desired quantity, respectively
	    char confirm, addOrder; // variables for confirming purchase and additional purchase, respectively
	    float total = 0.0; // variable for total cost of orders
	    int random = rand() % 100 + 1;
	    int i;
	    
	    // prices are different in buy and sell because of special items
	    time_t t = 0; // required to use srand
	    srand((unsigned) time(&t));
	    float phoenixDownPrice = (float) rand() / (float) RAND_MAX * (1200 - 500) + 500; // randomized phoenix down price
	    float elixiressencePrice = (float) rand() / (float) RAND_MAX * (2100 - 1500) + 1500; // randomized elixir essence price
	    float platinumingotPrice = (float) rand() / (float) RAND_MAX * (7000 - 5000) + 5000; // randomized platinum ingot Price
	    float goldenmateriaPrice = (float) rand() / (float) RAND_MAX * (5500 - 3500) + 3500; // randomized golden materia price
	    float scarletitePrice = (float) rand() / (float) RAND_MAX * (12000 - 8000) + 8000; // randomized scarletite price
	    float adamantitePrice = (float) rand() / (float) RAND_MAX * (20000 - 9500) + 9500; // SPECIAL ITEM randomized adamantite price
	    float darkmatterPrice = (float) rand() / (float) RAND_MAX * (50000 - 22000) + 22000; // SPECIAL ITEM randomized dark matter price
	    float trapezohedronPrice= (float) rand() / (float) RAND_MAX * (90000 - 60000) + 60000; // randomized trapezohedron price
	    
	        	//Special items will never sold out
			if(random < 30 || random == 30){ //has a 30% chance of being sold out.
			phoenixDownPrice = 0;
	    }
	    	if (random < 30 || random == 30) { // has a 30% chance of being sold out.
				elixiressencePrice = 0;
			}
				if(random < 30 || random == 30){ // has a 30% chance of being sold out.
					platinumingotPrice = 0;
				}
					if (random < 30 || random == 30) { // has a 30% chance of being sold out.
						goldenmateriaPrice = 0;
					}
						if(random < 30 || random == 30) { // has a 30% chance of being sold out.
							scarletitePrice = 0;
						}
									if (random < 30 ){ // has a 30% chance of being sold out.
												trapezohedronPrice= 0;
											}
	    
	    printf("Shopkeeper: Welcome! How may I be of service?");
	    printf ("\n\n");
	    printf("Day %d\n" , *day);
	    printf("Gil: %.2f \n", *balance);
	    printf("Debt: %.2f\n", *debt);
	    printf("\t\t\t\t\t       Item        On Hand    Price");
	    printf("\n");
	    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
		printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
	
	    printf("Note: If you can no longer afford an item, the day will proceed\n\n");
	    
	    do { // this do loop repeats when user wants to order items again & stops when balance is insufficient
	        printf("Shopkeeper: Buying an item? Which one? \n");
	        scanf("%d", &itemOrder);
	        
	        // this segment is for the Phoenix Down item order
	        if(itemOrder == 1) {
	            printf("How many Phoenix Down do you wish to buy?\n");
	            scanf("%d", &itemQuantity);
	            
	            while (itemQuantity * phoenixDownPrice > *balance) { // error handling if balance is not enough
	                printf("Insufficient balance. Only buy what you can afford.\n");
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * phoenixDownPrice;
	            *balance -= total;
	                
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	                
	            printf("Confirm Order? (Y/N) \n");
	            scanf("%c", &confirm); // throughout the program, i placed 2 scanf for char
	            scanf("%c", &confirm); // because it only works if 2 are present instead of 1 (only for char)
	                                   
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *phoenixdown += itemQuantity; // equation for updating the inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);        
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of Phoenix Down segment
	        
	        // this segment is for the Elixir Essence item
	        else if(itemOrder == 2) {
	            printf("How many Elixir Essence do you wish to buy?\n");
	            scanf("%d", &itemQuantity);
	            
	            while (itemQuantity * elixiressencePrice > *balance) {
	                printf("Insufficient balance. Only buy what you can afford.\n");  // error handling if
	                scanf("%d", &itemQuantity);                                   // balance is not enough
	            }
	            
	            total = itemQuantity * elixiressencePrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs for char since it won't work if only 1 is placed
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *elixiressence += itemQuantity; // equation for updating the elixir essence inventory
	
	    			
					printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);  
	                
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of elixir essence segment
	        
	        // this segment is for the platinum ingot order
	        else if(itemOrder == 3) {
	            printf("How many Platinum Ingot do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * platinumingotPrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * platinumingotPrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *platinumingot += itemQuantity; // equation for updating the 	 inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);  
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of platinum ingot segment
	               
				    // this segment is for the golden materia order
	        else if(itemOrder == 4) {
	            printf("How many Golden Materia do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * goldenmateriaPrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * goldenmateriaPrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *goldenmateria += itemQuantity; // equation for updating the 	 inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);  
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of golden materia segment
	        
	        // this segment is for the scarletite order
	        else if(itemOrder == 5) {
	            printf("How many Scarletite do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * scarletitePrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * scarletitePrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *scarletite += itemQuantity; // equation for updating the scarletite inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);  
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of scarletite segment
	        
	        // this segment is for the adamantite order
	        else if(itemOrder == 6) {
	            printf("How many Adamantite do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * adamantitePrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * adamantitePrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *adamantite += itemQuantity; // equation for updating the adamantite inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);  
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of adamantite segment
	        
	                // this segment is for the dark matter order
	        	else if(itemOrder == 7) {
	            printf("How many Dark Matter do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * darkmatterPrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * darkmatterPrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *darkmatter += itemQuantity; // equation for updating the dark matter inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);  
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of dark matter segment
	        
	            // this segment is for the trapezohedron order
	        	else if(itemOrder == 8) {
	            printf("How many Trapezohedron do you wish to order?\n");
	            scanf("%d", &itemQuantity);
	        
	            while (itemQuantity * trapezohedronPrice > *balance) {
	                printf("Insufficient balance. Order what you can afford.\n"); // error handling for balance
	                scanf("%d", &itemQuantity);
	            }
	            
	            total = itemQuantity * trapezohedronPrice;
	            *balance -= total;
	            
	            printf("That will cost you %.2f, which will leave you with a balance of %.2f.\n", total, *balance);
	            
	            printf("Confirm Order? (Y/N)\n");
	            scanf("%c", &confirm); // 2 scanfs again for char to make it work
	            scanf("%c", &confirm);
	            
	            if(confirm == 'Y' || confirm == 'y') {
	                
	                *trapezohedron += itemQuantity; // equation for updating the inventory
	                
	                printf("Item Purchased Confirmed. Here's your updated inventory and balance:\n\n");
					printf("Balance left: %.2f \n", *balance);
	    			printf("Debt: %.2f\n", *debt);
	                printf("\n");
	                printf("\t\t\t\t\t[1] Phoenix Down       %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   				printf("\t\t\t\t\t[2] Elixir Essence     %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    			printf("\t\t\t\t\t[3] Platinum Ingot     %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    			printf("\t\t\t\t\t[4] Golden Materia     %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    			printf("\t\t\t\t\t[5] Scarletite         %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    			printf("\t\t\t\t\t[6] Adamantite         %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    			printf("\t\t\t\t\t[7] Dark Matter        %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
					printf("\t\t\t\t\t[8] Trapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);  
	                
	            }
	            else if (confirm == 'N' || confirm == 'n') {
	                printf("Order Canceled.\n");
	                *balance += total;
	            }
	        } // end of trapezohedron segment
	        
	        else if(itemOrder > 8) { // error handling wherein program only allows user to choose between 1-8
	            printf("Choose a number between 1-8 only.\n");
	        }
	                // if balance is < the prices of items, user will not be able to buy again
	        if(*balance < phoenixDownPrice && (*balance < elixiressencePrice && *balance < platinumingotPrice && *balance < goldenmateriaPrice &&
			 *balance < goldenmateriaPrice && *balance < scarletitePrice && *balance < adamantitePrice && *balance < darkmatterPrice && *balance < trapezohedronPrice )){
	            printf("Cannot buy any more items. Balance is insufficient.\n\n");
	        }        
	        // however, if balance is > the prices of items, user is allowed to buy over & over again
	        else if (*balance > phoenixDownPrice || *balance > elixiressencePrice || *balance > platinumingotPrice|| *balance > goldenmateriaPrice
				|| *balance > scarletitePrice || *balance > adamantitePrice || *balance > darkmatterPrice || *balance > trapezohedronPrice){
	            printf("Do you wish to order more items? (Y/N)\n");
	            scanf("%c", &addOrder);
	        }                          // 2 scanf here to make the char work on my compiler
	        
			scanf("%c", &addOrder);
	    } while(addOrder == 'Y' || addOrder == 'y'); // this is the end of the do while loop, repeats once user
	                                                 // wants to order again under certain conditions
	    printf("-----End of Day %d-----\n", *day);   // %d refers to i in the main function, it updates the nth day
	    printf("=======================\n");
	    
	    
}
	
void sellrich (int *phoenixdown, int *elixiressence, int *platinumingot,int *goldenmateria, 
	int *scarletite, int *adamantite, int *darkmatter,int *trapezohedron, float *balance, int *day, float *debt) // for selling items in riches and minerals shop
{
		int i, itemSell, itemQuantity; // variables for the loop and the user's guess in selling, respectively
		float total = 0.0; // variable for total
		char confirm;
		int random = rand() % 100 + 1;
		
		time_t t = 0; // required to use srand
	    srand((unsigned) time(&t));
	    float phoenixDownPrice = (float) rand() / (float) RAND_MAX * (1200 - 500) + 500; // randomized phoenix down price
	    float elixiressencePrice = (float) rand() / (float) RAND_MAX * (2100 - 1500) + 1500; // randomized elixir essence price
	    float platinumingotPrice = (float) rand() / (float) RAND_MAX * (7000 - 5000) + 5000; // randomized platinum ingot Price
	    float goldenmateriaPrice = (float) rand() / (float) RAND_MAX * (5500 - 3500) + 3500; // randomized golden materia price
	    float scarletitePrice = (float) rand() / (float) RAND_MAX * (12000 - 8000) + 8000; // randomized scarletite price
	    float adamantitePrice = (float) rand() / (float) RAND_MAX * (30000 - 15000) + 15000; // randomized adamantite price
	    float darkmatterPrice = (float) rand() / (float) RAND_MAX * (70000 - 40000) + 40000; // randomized dark matter price
	    float trapezohedronPrice= (float) rand() / (float) RAND_MAX * (90000 - 60000) + 60000; // randomized trapezohedron price
	    
	            	//Special items will never sold out
			if(random < 30 || random == 30){ //has a 30% chance of being sold out.
			phoenixDownPrice = 0;
	    }
	    	if (random < 30 || random == 30) { // has a 30% chance of being sold out.
				elixiressencePrice = 0;
			}
				if(random < 30 || random == 30){ // has a 30% chance of being sold out.
					platinumingotPrice = 0;
				}
					if (random < 30 || random == 30) { // has a 30% chance of being sold out.
						goldenmateriaPrice = 0;
					}
						if(random < 30 || random == 30) { // has a 30% chance of being sold out.
							scarletitePrice = 0;
						}
									if (random < 30 ){ // has a 30% chance of being sold out.
												trapezohedronPrice= 0;
											}
	    
	    printf("Shopkeeper: Welcome! How may I be of service?");
	    printf ("\n\n");
	    printf("Day %d\n" , *day);
	    printf("Gil: %.2f \n", *balance);
	    printf("Debt: %.2f\n", *debt);
	    printf("\t\t\t\t\t        Item       On Hand   Price");
	    printf("\n");
	    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
		printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
		
		printf("Note: If you chose to type 0, it will end the day");
		
			do { // this do loop repeats when user wants to sell items again & stops when there is no item anymore
			        		printf("Shopkeeper: Selling an item? Which one? \n");
			    			scanf("%d", &itemSell);
			    	
							if (itemSell == 1){	
			    				printf ("How many Phoenix Down do you wish to sell?\n");
			    				scanf("%d", &itemQuantity);
			    		
					    			if (*phoenixdown < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					                	system("pause");
					        		}
					        		else if (itemQuantity > *phoenixdown) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * phoenixDownPrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
						    			printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
										
						            	*phoenixdown -= itemQuantity; // equation for updating the inventory
						            	system("pause");
									}
							} // End of Phoenix Down Sell Segment
					
							else if (itemSell == 2){
				    			printf ("How many Elixir Essence do you wish to sell?\n");
				    			scanf("%d", &itemQuantity);
				    		
						    		if (*elixiressence < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					                	system("pause");
					        		}
					        		else if (itemQuantity > *elixiressence) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * elixiressencePrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
						            	*elixiressence -= itemQuantity; // equation for updating the inventory
						            	system("pause");
									}
							} // End of elixir essence Sell Segment
						
							else if (itemSell == 3)
				    		{
					    		printf ("How many Elixir Essence do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
					    			if (*platinumingot < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					                	system("pause");
					        		}
					        		else if (itemQuantity > *platinumingot) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * platinumingotPrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
						            	*platinumingot -= itemQuantity; // equation for updating the inventory
									}
							} // End of platinum ingot Sell Segment
					
							else if (itemSell == 4)
					    	{
					    		printf ("How many Golden Materia do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
						    		if (*goldenmateria < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					                	system("pause");
					        		}
					        		else if (itemQuantity > *goldenmateria) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * goldenmateriaPrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
						            	*goldenmateria -= itemQuantity; // equation for updating the inventory
									}
							} // End of golden materia Sell Segment
					
							else if (itemSell == 5)
					    	{
					    		printf ("How many Scarletite do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
						    		if (*scarletite < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					        			system("pause");
					        		}
					        		else if (itemQuantity > *scarletite) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * scarletitePrice;
					            		*balance += total;
										printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
						            	*scarletite -= itemQuantity; // equation for updating the inventory
									}
							} // End of scarletite Sell Segment
					
							else if (itemSell == 6)
				    		{
					    		printf ("How many Adamantite do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
						    		if (*adamantite < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					        			system("pause");
					        		}
					        		else if (itemQuantity > *adamantite) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * adamantitePrice;
					            		*balance += total;
										printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
										
						            	*adamantite -= itemQuantity; // equation for updating the inventory
									}
							} // End of adamantite Sell Segment
					
							else if (itemSell == 7)
					    	{
					    		printf ("How many Dark Matter do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
						    		if (*darkmatter < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					        			system("pause");
					        		}
					        		else if (itemQuantity > *adamantite) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * darkmatterPrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
										
						            	*darkmatter -= itemQuantity; // equation for updating the inventory
									}
							} // End of dark matter Sell Segment
					
							else if (itemSell == 8)
					    	{
					    		printf ("How many Trapezohedron do you wish to sell?\n");
					    		scanf("%d", &itemQuantity);
					    		
					    		if (*trapezohedron < 1){ // if phoenix down inventory is empty, no item will be sold
					                	printf("You don't have this item!\n");
					        			system("pause");
					        		}
					        		else if (itemQuantity > *adamantite) {
					        			printf("You don't have enough item!\n");
					        			scanf("%d", &itemQuantity);
									}
			        				else {
			        					total = itemQuantity * trapezohedronPrice;
					            		*balance += total;
					            		printf("Item Sold. Here's your updated inventory and balance:\n\n");
										printf("Balance left: %.2f \n", *balance);
						    			printf("Debt: %.2f\n", *debt);
										printf("\t\t\t\t\t        Item       On Hand   Price");
									    printf("\n");
									    printf("\t\t\t\t\t[1] Phoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
									    printf("\t\t\t\t\t[2] Elixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
									    printf("\t\t\t\t\t[3] Platinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
									    printf("\t\t\t\t\t[4] Golden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
									    printf("\t\t\t\t\t[5] Scarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
									    printf("\t\t\t\t\t[6] Adamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
									    printf("\t\t\t\t\t[7] Dark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
										printf("\t\t\t\t\t[8] Trapezohedron    %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);
										
										printf("Note: If you chose to type 0, it will end the day");
										
						            	*trapezohedron -= itemQuantity; // equation for updating the inventory
									}
							} // End of trapezohedron Sell Segment
					} while (confirm == 'Y' || confirm == 'y'); // end of this do loop that repeats when user wants to sell items again & stops when there is no item anymore		
	    
		printf("Balance left: %.2f \n", *balance);
	    printf("Debt: %.2f\n", *debt);
	    printf("\n");
	    printf("\t\t\t\t\tPhoenix Down       %dx      (%.2f)\n", *phoenixdown, phoenixDownPrice);
	   	printf("\t\t\t\t\tElixir Essence     %dx      (%.2f)\n", *elixiressence ,elixiressencePrice);
	    printf("\t\t\t\t\tPlatinum Ingot      %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    printf("\t\t\t\t\tGolden Materia       %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
		printf("\t\t\t\t\tScarletite          %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    printf("\t\t\t\t\tAdamantite      %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    printf("\t\t\t\t\tDark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
		printf("\t\t\t\t\tTrapezohedron      %dx     (%.2f)\n", *trapezohedron ,trapezohedronPrice);    
	    printf("-----End of Day %d-----\n", *day); // updates of balance, inventories, and end of day;
	    
	    system("pause");
}
	
void shoprich (int *phoenixdown, int *elixiressence, int *platinumingot,int *goldenmateria, 
	int *scarletite, int *adamantite, int *darkmatter,int *trapezohedron, float *balance, int *day, float *debt) // for riches and minerals shop
{
	    int mon;
	    int random = rand() % 100 + 1;
	    int i;
	    
		time_t t = 0; // required to use srand
	    srand((unsigned) time(&t));
	    float phoenixDownPrice = (float) rand() / (float) RAND_MAX * (1200 - 500) + 500; // randomized phoenix down price
	    float elixiressencePrice = (float) rand() / (float) RAND_MAX * (2100 - 1500) + 1500; // randomized elixir essence price
	    float platinumingotPrice = (float) rand() / (float) RAND_MAX * (7000 - 5000) + 5000; // randomized platinum ingot Price
	    float goldenmateriaPrice = (float) rand() / (float) RAND_MAX * (5500 - 3500) + 3500; // randomized golden materia price
	    float scarletitePrice = (float) rand() / (float) RAND_MAX * (12000 - 8000) + 8000; // randomized scarletite price
	    float adamantitePrice = (float) rand() / (float) RAND_MAX * (30000 - 15000) + 15000; // randomized adamantite price
	    float darkmatterPrice = (float) rand() / (float) RAND_MAX * (70000 - 40000) + 40000; // randomized dark matter price
	    float trapezohedronPrice= (float) rand() / (float) RAND_MAX * (90000 - 60000) + 60000; // randomized trapezohedron price
	    
	            	//Special items will never sold out
			if(random < 30 || random == 30){ //has a 30% chance of being sold out.
			phoenixDownPrice = 0;
	    }
	    	if (random < 30 || random == 30) { // has a 30% chance of being sold out.
				elixiressencePrice = 0;
			}
				if(random < 30 || random == 30){ // has a 30% chance of being sold out.
					platinumingotPrice = 0;
				}
					if (random < 30 || random == 30) { // has a 30% chance of being sold out.
						goldenmateriaPrice = 0;
					}
						if(random < 30 || random == 30) { // has a 30% chance of being sold out.
							scarletitePrice = 0;
						}
									if (random < 30 ){ // has a 30% chance of being sold out.
												trapezohedronPrice= 0;
											}
	    
	    printf("Shopkeeper: Welcome! How may I be of service?");
	    printf ("\n");
	    printf("Day %d\n" , *day);
	    printf("Gil: %.2f \n", *balance);
	    printf("Debt: %.2f\n", *debt);
	    printf("\t\t\t\t\t    Item       On Hand    Price");
	    printf("\n");
	    printf("\t\t\t\t\tPhoenix Down     %dx     (%.2f)\n", *phoenixdown, phoenixDownPrice);
	    printf("\t\t\t\t\tElixir Essence   %dx     (%.2f)\n", *elixiressence ,elixiressencePrice);
	    printf("\t\t\t\t\tPlatinum Ingot   %dx     (%.2f)\n", *platinumingot ,platinumingotPrice);
	    printf("\t\t\t\t\tGolden Materia   %dx     (%.2f)\n", *goldenmateria ,goldenmateriaPrice);
	    printf("\t\t\t\t\tScarletite       %dx     (%.2f)\n", *scarletite ,scarletitePrice);
	    printf("\t\t\t\t\tAdamantite       %dx     (%.2f)\n", *adamantite ,adamantitePrice);
	    printf("\t\t\t\t\tDark Matter      %dx     (%.2f)\n", *darkmatter ,darkmatterPrice);
		printf("\t\t\t\t\tTrapezohedron    %dx     (%.2f)\n\n", *trapezohedron ,trapezohedronPrice);
		
		printf ("Note: If you try to sell even if you don't have an item in your inventory it will skip the day\n");
		printf ("so make sure you have atleast 1 in your inventory when selling.\n\n");
		
		printf("\t\t\t\t\t[1] Buy\n");
		printf("\t\t\t\t\t[2] Sell\n");
		printf("\t\t\t\t\t[3] Skip Day\n");
	    printf("Your Choice: ");
	    scanf("%d", &mon);
	    
	    switch (mon){
	    	case 1: richbuy (&*phoenixdown, &*elixiressence, &*platinumingot,&*goldenmateria, 
		 &*scarletite, &*adamantite, &*darkmatter, &*trapezohedron, &*balance, &*day, &*debt); break;
	    	case 2: sellrich (&*phoenixdown, &*elixiressence, &*platinumingot,&*goldenmateria, 
		 &*scarletite, &*adamantite, &*darkmatter, &*trapezohedron, &*balance, &*day, &*debt); break; 
	    	case 3: skip(&*day);break;
		}
	    
			    
}
	
void merchant (float *balance, float *debt, int *day, float *deposit) // merchant place where you can deposit, withdraw, ask for additional loan, and pay loan
{
		float input1; // variable for entered amount
	    char input2, input3; // variables for confirming the amount and paying, depositing, loan, and withdrawing again, respectively
	    int nMerchant;
	    printf("Merchant of the Rift: Are you ready to pay your debt?\n");
	    	printf("Day %d\n" , *day);
	    	printf("Gil: %.2f \n", *balance);
	    	printf("Debt: %.2f\n", *debt);
	    	printf("Stored Gil:%.2f\n", *deposit);
	        printf ("\t\t\t\t\t[1] Deposit Gil \n");
	        printf ("\t\t\t\t\t[2] Withdraw Gil \n");
	        printf ("\t\t\t\t\t[3] Ask for additional loan \n");
	        printf ("\t\t\t\t\t[4] Pay off Debt \n");
	        printf ("\t\t\t\t\t[5] Skip day\n");
	        printf ("Your choice: ");
			scanf ("%d",&nMerchant);
	        
	        if (nMerchant == 1){
	        	    do { // do loop if user wants to deposit again
	        
	        do { // do loop if entered amount is > balance
	            printf("How much would you like to deposit?\n");
	            scanf("%f", &input1);
	                   
	            if(input1 >= *balance) //user will not be allowed to pay if entered amount is too big
	                printf("You cannot deposit what you do not have! Double check your balance.\n");
	    
	        } while(input1 > *balance); // end of loop for error handling
	        
	        printf("You will deposit a total of %.2f. Confirm deposit? (Y/N)\n", input1);
	        scanf("%c", &input2); // 2 scanf again for char input
	        scanf("%c", &input2); // It doesn't work on my compiler if I only input 1 scanf
	
	        
	        if(input2 == 'Y' || input2 == 'y') // displayed if user confirmed the amount
	        {
	            printf("Deposit confirmed!\n");
	            *balance -= input1; // amount will be deducted from the balance
	            *deposit = *deposit +=input1;    // amount will be added from the stored Gil
	            
	            printf("-----------------------\n");
	            printf("Updated Balance: %.2f\n", *balance);
	            printf("Updated Debt: %.2f\n", *debt);      // updates of the balance, debt, and deposit
	            printf("Updated stored Gil:%.2f\n", *deposit);
	            printf("-----------------------\n");
	            printf("-----End of Day %d-----\n", *day);
	           // printf("=======================\n");
	        }
	        else if(input2 == 'N' || input2 == 'n') // displayed if payment is canceled
	        {
	            printf("Deposit Canceled. Deposit again? (1 for Y/ 0 for N)\n");
	            scanf("%c", &input3); // user will have the chance to deposit again
	        }
	        scanf("%c", &input3);
	    } while (input3 == 'Y' || input3 == 'y'); // end of loop for paying again
	    
	    if(input3 == 'N' || input3 == 'n')
	        printf("-----End of Day %d-----\n", *day);
	        printf("=======================\n");
			}
		
			
			if (nMerchant == 2){
				    do { // do loop if user wants to withdraw again
	        
		        do { // do loop if entered amount is > balance
		            printf("How much would you like to withdraw?\n");
		            scanf("%f", &input1);
		                   
		            if(input1 >= *deposit) //user will not be allowed to pay if entered amount is too big
		                printf("You cannot pay what you do not have! Double check your balance.\n");
		    
		        } while(input1 > *deposit); // end of loop for error handling
	        
		        printf("You will withdraw a total of %.2f. Confirm withdraw? (Y/N)\n", input1);
		        scanf("%c", &input2); // 2 scanf again for char input
		        scanf("%c", &input2);
	
	        
		        if(input2 == 'Y' || input2 == 'y') // displayed if user confirmed the amount
		        {
		            printf("Withdraw confirmed!\n");
		            *balance += input1; // amount will be added from the balance
		            *deposit = input1 -= *deposit;    // amount will be deducted from the stored Gil
		            
		            printf("-----------------------\n");
		            printf("Updated Balance: %.2f\n", *balance);
		            printf("Updated Debt: %.2f\n", *debt);      // updates of the balance, debt, and deposit
		            printf("Updated stored Gil:%.2f\n", *deposit);
		            printf("-----------------------\n");
		            printf("-----End of Day %d-----\n", *day);
		           // printf("=======================\n");
		        }
		        else if(input2 == 'N' || input2 == 'n') // displayed if payment is canceled
		        {
		            printf("Withdraw Canceled. Withdraw again?\n");
		            scanf("%c", &input3); // user will have the chance to withdraw again
		        }
		        scanf("%c", &input3);
			    } while (input3 == 'Y' || input3 == 'y'); // end of loop for withdrawing again
			    
			    if(input3 == 'N' || input3 == 'n')
			        printf("-----End of Day %d-----\n", *day);
			        printf("=======================\n");
	
			}
			
			
			if (nMerchant == 3){
				do { // do while loop repeats when user wants to take a loan again
	        printf("How much would you loan? \n");
	        scanf("%f", &input1);
	        
	        printf("You have decided to borrow %.2f. Confirm loan? (Y/N)\n", input1);
	        scanf("%c", &input2); // 2 scanfs to make it work
	        scanf("%c", &input2); // because char won't work if there's only 1 scanf in my compiler
	        
	        if(input2 == 'Y' || input2 == 'y') // displayed if loan is confirmed
	        {
	            printf("Loan completed!\n");
	            *balance += input1; // the loan is added to the balance
	            *debt += input1;    // debt is increased as well
	            
	            printf("---------------\n");
	            printf("Updated Balance: %.2f\n", *balance); // updates on balance and debt
	            printf("Updated Debt: %.2f\n", *debt);
	            printf("---------------\n");
	        }
	        else if(input2 == 'N' || input2 == 'n') // displayed if loan is canceled
	        {
	            printf("Loan is canceled. Take a loan again? (Y/N)\n");
	            scanf("%c", &input3); // user may be able to take a loan again
	        }
	        scanf("%c", &input3);
	    } while(input3 == 'Y' || input3 == 'y'); // end of do while loop
	    
	    printf("-----End of Day %d-----\n", *day); // displayed when user does not want to take a loan anymore
	    printf("=======================\n");
			}
	        
	        
	        if (nMerchant ==4){
	        	    do { // do loop if user wants to pay debt again
	        
	        do { // do loop if entered amount is > balance
	            printf("How much would you like to pay?\n");
	            scanf("%f", &input1);
	                   
	            if(input1 >= *balance) //user will not be allowed to pay if entered amount is too big
	                printf("You cannot pay what you do not have! Double check your balance.\n");
	    
	        } while(input1 > *balance); // end of loop for error handling
	        
	        printf("You will pay a total of %.2f. Confirm payment? (Y/N)\n", input1);
	        scanf("%c", &input2); // 2 scanf again for char input
	        scanf("%c", &input2);
	        
	        if(input2 == 'Y' || input2 == 'y') // displayed if user confirmed the amount
	        {
	            printf("Payment confirmed!\n");
	            *balance -= input1; // amount will be deducted from the balance
	            *debt -= input1;    // amount will be deducted from the debt
	            
	            printf("-----------------------\n");
	            printf("Updated Balance: %.2f\n", *balance);
	            printf("Updated Debt: %.2f\n", *debt);      // updates of the balance and debt
	            printf("-----------------------\n");
	            printf("-----End of Day %d-----\n", *day);
	           // printf("=======================\n");
	        }
	        else if(input2 == 'N' || input2 == 'n') // displayed if payment is canceled
	        {
	            printf("Payment Canceled. Pay debt again? (1 for Y/ 0 for N)\n");
	            scanf("%c", &input3); // user will have the chance to pay again
	        }
	        scanf("%c", &input3);
	    } while (input3 == 'Y' || input3 == 'y'); // end of loop for paying again
	    
	    if(input3 == 'N' || input3 == 'n')
	        printf("-----End of Day %d-----\n", *day);
	        printf("=======================\n");
			}
			
			if (nMerchant == '5'){
				printf("---------------------\n");
			    printf("You chose to do nothing and skip the day\n");
			    printf("-----End of Day %d-----\n", *day);   // pointer day is updated
			    printf("=======================\n");
			}
}
void endDay(float *balance, float *debt) // this is 
{
	    int remaining; // variable used to check if good or bad ending is achieved.
	    printf ("\n\nGil: %.2f\n", *balance);
	    printf ("\n\nDebt: %.2f\n", *debt);
	    printf("\n\n\n\t\t\t\t\t---------------------------------------------\n");
	    printf("\t\t\t\t\tDay 30: You have reached the end of the game!\n");
	    printf("\t\t\t\t\t---------------------------------------------\n\n\n\n\n");
	    printf("\t\t\tYour remaining debt will be subtracted from your remaining balance. \n\n\n\n\n");
	    printf("\t\t\t\t\t------------------LOADING--------------------\n\n");
	    system ("break");
	    
	    remaining = *balance - *debt; // equation for the conditionals below
	    printf("Total Profit: %.2f\n", *balance - *debt);
	    if(remaining == 0) { // this portion is for the good ending
	        printf("\t\t\t\t\t==========================================\n");
	        printf("\t\t\t\t\t                Congrats!\n"); // achieved if you have succesfully paid your debt after day 30
	        printf("\t\t\t\t\t------------------------------------------\n");
	        printf("\t\t\t\t\t You have successfully paid your debts :D \n");
	        printf("\t\t\t\t\t==========================================\n");
	    }
	    
	    else {
	        printf ("\t\t\t\t\t==================================\n"); // this portion is for the bad ending
	        printf ("\t\t\t\t\t       Sorry Gilgamesh!\n"); // achieved if you did not have enough money to pay off your debt after day 30
	        printf ("\t\t\t\t\t----------------------------------\n");
	        printf ("\t\t\t\t\t   You failed to pay your debt.\n"); 
	        printf ("\t\t\t\t\t   Better luck next time! :( \n");
	        printf ("\t\t\t\t\t==================================\n");
	    }
	    
}		
void menu() // If the user goes to this place nothing will happen, the user will only waste a day if the user decided to go here 
{
	printf("\t\t\t\t\t\t\"GILGAMESH'S MEGA GIL ADVENTURES\"\n\n");
	printf("Nwonknu: Hello Traveler.\n\n\n");
	system("pause");
	printf("\n\nNwonknu: Greetings!\n\n");
	system("pause");
	printf ("\n\nNwonknu: Ah, I see that you are a warrior lost in the rift who ends-up travelling into different worlds.\n");
	printf ("\t Ah, you're a weapon collector who's in search for the legendary weapon \"Excalibur\", and I see that you\n");
	printf ("\t aim to travel to different worlds to one day come up with that legendary weapon. Armed with extremely \n");
	printf ("\t powerful weapons you've collected during your recent travels, you set off on a journey to other worlds.\n");
	printf ("\t However, I think you've realized that in order for you to do this, you need money during your travels\n");
	printf ("\t You need money to purchase the equipment that you will need during your battles and more importantly, to\n");
	printf ("\t buy rare weapons that you set your eyes on. The only reasonable you can obtain money is by earning them\n");
	printf ("\t in an honest manner, and that is through buying and selling goods you purchases from other worlds\n");
	system("pause");
	printf("\n\nYou: Weirdo...\n");
	printf("\n\nYou left.\n");
	printf("\n\nYou wasted a whole day.\n");
	system("pause");
}
int main ()
{
		int ask;
		int nMainRift;
		float balance = 20000.00; // variable for the balance, which initially starts from 20000.00
	    float debt = 50000.00; // variable for the debt, which initially starts from 50000.00
	    float deposit = 0; // variable for the stored gil in merchant of the rift
	    int phoenixdown = 0, elixiressence = 0, platinumingot = 0, goldenmateria = 0; // variables for the item inventories
	    int scarletite = 0, adamantite = 0, darkmatter = 0, trapezohedron = 0;// variables for the item inventories
	    int i = 1; // variable for the day number
	    int decision; // variable for the decision of the user per day
	    char again;
	    
	    
		// for loop for day 1-30 where user can decide 1 activity per day
	    // it will start from day 1 and will end after day 30 arrives
		for(i = 1; i <= 30; i++)
	    {
	        if(i > 1) {
	            debt += debt * 0.15; // as each day progresses, debt is increased by 15%
	            deposit += deposit * 0.10; // money deposited from the merchant increases by 10% each day
	        }
			
		do{
			system("cls");
			printf ("Day %d\n", i);
			printf ("Gil: %.2f\n", balance);
	    	printf ("Debt: %.2f\n", debt);
	    	printf ("Stored Gil:  %.2f\n\n", deposit);
			printf ("Gilgamesh:Where should I take my travels take me to?\n");
			printf ("\n");
			printf ("\t\t\t\t\t[1]  - Nwonknu\n");
			printf ("\t\t\t\t\t[2]  - Tycoon Meteor's Mineral\n");
			printf ("\t\t\t\t\t[3]  - Pulsian Restoratives\n");
			printf ("\t\t\t\t\t[4]  - Archadian Luxuries\n");
			printf ("\t\t\t\t\t[5]  - Cid's Magical Escapades\n");
			printf ("\t\t\t\t\t[6]  - Gaian Gratitudes\n");
			printf ("\t\t\t\t\t[7]  - Riches and Minerals of Spira\n");
			printf ("\t\t\t\t\t[8]  - Go see the Merchant of the Rift\n");
			printf ("\t\t\t\t\t[9]  - Skip day\n");
			printf ("\t\t\t\t\t[10] - Quit Game\n");
			printf ("\n");
			printf ("Your choice: ");
			scanf ("%d",&nMainRift);
		} while (nMainRift < 1 || nMainRift > 10);
		
		switch (nMainRift)
			{
			case 1: menu (); break;
			case 2: printf ("*****************************\n Tycoon Meteor's Mineral\n*****************************\n"); shopty (&phoenixdown, &elixiressence, &platinumingot,&goldenmateria, 
				&scarletite, &adamantite, &darkmatter, &trapezohedron, &balance, &i, &debt); break;
			case 3: printf ("*****************************\n Pulsian Restoratives\n*****************************\n"); shoppul (&phoenixdown, &elixiressence, &platinumingot,&goldenmateria, 
				&scarletite, &adamantite, &darkmatter, &trapezohedron, &balance, &i, &debt);break;
			case 4: printf ("*****************************\n Archadian Luxuries\n*****************************\n"); shoparch (&phoenixdown, &elixiressence, &platinumingot,&goldenmateria, 
				&scarletite, &adamantite, &darkmatter, &trapezohedron, &balance, &i, &debt);break;
			case 5: printf ("*****************************\n Cid's Magical Escapades\n*****************************\n");shopcid (&phoenixdown, &elixiressence, &platinumingot,&goldenmateria, 
				&scarletite, &adamantite, &darkmatter, &trapezohedron, &balance, &i, &debt);break; 
			case 6: printf ("*****************************\n Gaian Gratitudes\n*****************************\n"); shopgaian (&phoenixdown, &elixiressence, &platinumingot,&goldenmateria, 
				&scarletite, &adamantite, &darkmatter, &trapezohedron, &balance, &i, &debt);break;
			case 7: printf ("*****************************\n Riches and Minerals of Spira\n*****************************\n");shoprich (&phoenixdown, &elixiressence, &platinumingot,&goldenmateria, 
				&scarletite, &adamantite, &darkmatter, &trapezohedron, &balance, &i, &debt);break; 
			case 8: printf ("********************************\n Go see the Merchant of the Rift\n********************************\n"); merchant (&balance, &debt, &i, &deposit);break;
			case 9: skip(&i); break;
			case 10: printf("Bye!"); return(0); break;
			}		
		}
	
		endDay(&balance, &debt);
		
		printf("Do you want to play again? Y/N\n");
		scanf ("%c", &again); // 
		scanf ("%c", &again); // because it only works if 2 are present instead of 1 (only for char)
		
		if ( again == 'Y' || again == 'y'){
			main ();
		}
		else{
			return;
		}
			
		return 0;
}
