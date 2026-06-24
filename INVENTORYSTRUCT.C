#include<stdio.h>

struct product
{
    int id;
    int qty;
};

int main()
{
    struct product p[5] =
    {
        {101,5},
        {102,4},
        {103,3},
        {104,2},
        {105,1}
    };

    int choice,pid,pqty,i;

    do
    {
        printf("\n===== DMART =====\n");
        printf("1. Stock Available\n");
        printf("2. Purchase Item\n");
        printf("3. Checkout\n");

        printf("Enter Choice : ");
        scanf("%d",&choice);

        if(choice==1)
        {
            printf("\nProduct ID\tQuantity\n");

            for(i=0;i<5;i++)
            {
                printf("%d\t\t%d\n",p[i].id,p[i].qty);
            }
        }

        else if(choice==2)
        {
            printf("Enter Product ID : ");
            scanf("%d",&pid);

            printf("Enter Quantity : ");
            scanf("%d",&pqty);

            for(i=0;i<5;i++)
            {
                if(pid==p[i].id)
                {
                    if(pqty<=p[i].qty)
                    {
                        p[i].qty = p[i].qty - pqty;
                        printf("Item Purchased Successfully\n");
                    }
                    else
                    {
                        printf("Insufficient Stock\n");
                    }
                }
            }
        }

        else if(choice==3)
        {
            printf("Thank You For Shopping\n");
        }

        else
        {
            printf("Invalid Choice\n");
        }

    }while(choice!=3);

    return 0;
}