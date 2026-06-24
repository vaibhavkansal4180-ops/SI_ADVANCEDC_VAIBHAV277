#include <stdio.h>

int main()
{
    int id[] = {101,102,103,104,105,106,107};
    int qty[] = {4,3,2,5,6,2,1};

    int choice;
    int pid, purchase_qty;
    int cart = 0;

    do
    {
        printf("\n\t====== DMART ======\n");
        printf("\t1. Stock Available\n");
        printf("\t2. Purchase Item\n");
        printf("\t3. Checkout\n");

        printf("Enter Choice : ");
        scanf("%d",&choice);

        while(choice < 1 || choice > 3)
        {
            printf("You have entered invalid choice !!!\n");
            printf("Enter Correct Choice : ");
            scanf("%d",&choice);
        }

        if(choice == 1)
        {
            printf("\nProduct ID\tQuantity\n");

            for(int i=0; i<sizeof(id)/sizeof(id[0]); i++)
            {
                printf("%d\t\t%d\n",id[i],qty[i]);
            }
        }

        else if(choice == 2)
        {
            printf("\nEnter Product ID : ");
            scanf("%d",&pid);

            int found = 0;

            for(int i=0; i<sizeof(id)/sizeof(id[0]); i++)
            {
                if(id[i] == pid)
                {
                    found = 1;

                    printf("Available Quantity = %d\n",qty[i]);
                    printf("Enter Quantity to Purchase : ");
                    scanf("%d",&purchase_qty);

                    if(purchase_qty <= qty[i] && purchase_qty > 0)
                    {
                        qty[i] -= purchase_qty;
                        cart += purchase_qty;

                        printf("Item added to cart successfully.\n");
                    }
                    else
                    {
                        printf("Insufficient stock!\n");
                    }
                    break;
                }
            }

            if(found == 0)
            {
                printf("Invalid Product ID!\n");
            }
        }

        else if(choice == 3)
        {
            printf("\n===== CHECKOUT =====\n");
            printf("Total Items Purchased = %d\n",cart);
            printf("Thank You For Shopping!\n");
        }

    } while(choice != 3);

    return 0;
}