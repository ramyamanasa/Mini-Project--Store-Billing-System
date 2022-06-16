#include<stdio.h>
#include<string.h>

float getPrice(int CodeList[25], float PriceList[25], int nCode);
char name[250];
char cname[250];

void main()
{
     int i,j;

     int codes[25] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125};
     float prices[25] = {35, 41, 50, 120, 100, 159, 49, 10, 120, 45, 20, 199, 48, 99, 30, 20, 56, 70, 80, 95, 445, 88, 30, 99, 102};
     char items[25][40]={
     "Floor Cleaner",
     "Salt Packet",
     "Diary milk",
     "Soup packet",
     "Jim Jam",
     "Vermicelli",
     "Lip Balm",
     "Match box",
     "Surf Excel",
     "Dove shampoo",
     "Pears soap",
     "Body Lotion",
     "Chocolates",
     "Led bulbs",
     "Sweeping mop",
     "Diet coke",
     "mosquito bat",
     "Pasta Sauce",
     "Pain balm",
     "Cold Drink",
     "Special Rice",
     "Tooth paste",
     "Lays Chips",
     "Coffee Powder",
     "Tea powder"
     };

     unsigned int numtotal;
     int purchasedcode[25], quantity[25];
     float fTotalPrice = 0.0;

     printf("\t\tWelcome To Billing System\n");

     printf("Items in the Store:\n");
     printf("S.No. \tCode \t\tItem \t\t\tPrice\n");
     printf("----------------------------------------------------------------------------\n");

     for (i=0; i<25; i++){
        printf("%d \t%d \t\t%s \t\t\t%.2f\n", i+1, codes[i], items[i], prices[i]);
     }


     printf("\n");
     printf("Enter the number of items purchased:\n");
     scanf("%d",&numtotal);
     if(numtotal < 1 || numtotal > 25) {
        printf("Invalid number or number of Items is limited to 25 for now\n");
        return;
     }

     printf("\n");
     //for loop to to read the purchased item code and quantity
     printf("Enter the codes of each item purchased along with quantity:\n");
     for(j=0; j<numtotal; j++)
     {
         scanf("%d %d", &purchasedcode[j], &quantity[j]);
         if (purchasedcode[j] < 101 || purchasedcode[j] > 125) {
            printf("Invalid Code\n");
            return;
         }

         if (quantity[j] <= 0) {
            printf("Invalid Quantity\n");
            return;
         }
     }

      printf("\n");
      //for loop to get price based on code and multiply with quantity and add total price

     printf("Please Enter the following details. \n\n");

	 printf("Cashier's Name: ");
	 scanf("%s",name);
	 printf("\n");
	 printf("Customer's Name: ");
	 scanf("%s",cname);

	 printf("\n");

     printf("S.No.   Code      Item  \tQty     Price\n");
     printf("\n");

     for(j=0; j<numtotal; j++)
     {
         float itemprice = 0.0, qtyprice = 0.0;
         itemprice = getPrice(codes, prices, purchasedcode[j]);
         qtyprice = itemprice * quantity[j];
         printf("%d        %d     %s \t%d      %.2f\n", j+1, purchasedcode[j], items[j], quantity[j], qtyprice);
         fTotalPrice += qtyprice;
     }

     printf("----------------------------------------------------------------\n");
     printf("Total Price: %.2f\n", fTotalPrice);

     return;
}


float getPrice(int CodeList[25], float PriceList[25], int nCode)
{
    int nIndex = -1;
    //for loop to get index of the code in the code list
    int i;

    for(i = 0; i < 25; i++) {
        if(CodeList[i] == nCode) {
            nIndex = i;
            break;
        }
    }

    if(nIndex == -1) {
        return 0.0;
    }

    // from the index, get the price and return it. return 0.0 if not found.
    return PriceList[nIndex];
}
