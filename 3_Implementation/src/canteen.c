#include "canteen.h"
int start(int check)
{
    //system("cls");
    int choice;
    printf("\t\t\t.---------------------------------------.\n");
    printf("\t\t\t|\t WELCOME TO LTTS CAFTERIA\t|\n");
    printf("\t\t\t'---------------------------------------'\n");
    if(check)
        return check;

    if(!loginpage("LTTS","104694"))
    {
        printf("\nAccess denied\n\nProgram ending.....\n\n");
        exit(0);
    }
    //system("cls");
    printf("\n\nHiii! WELCOME TO LTTS CAFTERIA\n");
    do
    {
        printf("\n1. TAKE ORDER\n");
        printf("\n2. MANAGE INVENTORY\n");
        printf("\n3. ABOUT LTTS CAFTERIA\n");
        printf("\n4. RECORDS\n");
        printf("\n5. EXIT\n");
        printf("\n\tEnter your choice:\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:takeorder();
                    break;
            case 2: manageinventory();
                    break;
            case 3: aboutltts();
                    break;
            case 4: records();
                    break;        
            case 5: exit(0);
            default: printf("Invalid choice");
                    break;                               
        }
    }while(choice!=5);
    return 0;
}

//Function definitions
int loginpage(char usrname[], char pwsd[])
{
    int i=0;
    char c = ' ';
    //char username[] = "LTTS";
    char username[15];
    //char password[] = "104694";
    char password[15];
    printf("\n\tENTER THE USER NAME:\t");
    //scanf("%s",username);
    strcpy(username,usrname);
    strcpy(password,pwsd);
    printf("\n\tENTER THE PASSWORD:\t");
while (i<=9){
    password[i]=//getch();
    c=password[i];
    if(c==13) break;
    else printf("*");
    i++;
}
password[i]='\0';
i=0;
    
    if(!(strcmp(username,"LTTS")) && !(strcmp(password,"104694")))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

void manageinventory()
{
    int choice;
    printf("\n");
    do{
    printf("\t\tYOU ARE IN MANAGE INVENTORY PAGE\n");
    printf("\n1. EDIT PRICE\n");
    printf("\n2. ADD QUANTITY\n");
    printf("\n3. VIEW INVENTORY\n");
    printf("\n4. ADD NEW PRODUCT\n");
    printf("\n5. BACK TO MAIN PAGE\n");
    printf("\t Enter your choice(1-5):\t");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1: editprice();
                break;
        case 2: addquantity();
                break;
        case 3: viewinventory();
                break;    
        case 4: addproduct();
                break;
        case 5: break;         
        default:printf("Invalid choice"); 
                break;                 
    }

    }while(choice!=5);
}

int editprice()
{
    viewinventory();
    int n,found=0;
    printf("Enter the ID number of the product you want to edit:\t");
    scanf("%d",&n);
    fptr= fopen("Inventory.dat","rb+");
    //For testing purpose only
    if(fptr==NULL)
        return 0;
    else
        return 1;
    if(fptr==NULL)
    {
        printf("\n\tOOPS!! THE FILE CANNOT BE OPENED\n");
        printf("\n\n\n Program is closing ....");
        fclose(fptr);
        //getch();
        exit(0);
    }
    while(fread(&Products,sizeof(Products),1,fptr)>0)
    {
        if(n==Products.product_id)
        {
            printf("\n\tEnter the new price:\t");
            scanf("%f",&Products.product_price);
            fseek(fptr,-sizeof(Products),1);
            fwrite(&Products,sizeof(Products),1,fptr);
            printf("%s Price is updated\n",Products.product_name);
            found=1;
            break;
            //viewinventory();
        }
    }
    fclose(fptr);
    if(found==0)
        printf("Product not found\n");
        //getch();
    return 0;
}

int addquantity()
{
    viewinventory();
    int n,found=0;
    int tempquantity=0;
    fptr= fopen("Inventory.dat","rb+");
    if(fptr==NULL)
        return 0;
    else
        return 1;
    printf("Enter the ID number of the product you want to edit:\t");
    scanf("%d",&n);
    if(fptr==NULL)
    {
        printf("\n\tOOPS!! THE FILE CANNOT BE OPENED\n");
        printf("\n\n\n Program is closing ....");
        fclose(fptr);
        //getch();
        exit(0);
    }
    while(fread(&Products,sizeof(Products),1,fptr)>0)
    {
        if(n==Products.product_id)
        {
            tempquantity=Products.product_quantity;
            printf("\n\tEnter the quantity:\t");
            scanf("%d",&Products.product_quantity);
            Products.product_quantity+=tempquantity;
            fseek(fptr,-sizeof(Products),1);
            fwrite(&Products,sizeof(Products),1,fptr);
            printf("%s Quantity Update\n",Products.product_name);
            found=1;
            break;
        }
    }
    fclose(fptr);
    if(found==0)
        printf("Product not found\n");
        //getch();
    return 0;
}

//Add product function
void addproduct()
{
    FILE *fptr1;
    fptr = fopen("Inventory.dat","ab");
    fptr1 = fopen("Salesrecord.dat","ab");
    if(fptr==NULL||fptr1==NULL)
    {
        printf("\n\tOOPS!! THE FILE CANNOT BE OPENED\n");
        printf("\n\n\n Program is closing ....");
        fclose(fptr);
        fclose(fptr1);
        //getch();
        exit(0);
    }
    printf("\n\t You are in ADD NEW PRODUCT PAGE\n");
    printf("\n\tEnter the ID of the product:\t");
    scanf("%d",&Products.product_id);
    printf("\n\tEnter the NAME of the product:\t");
    scanf("%s",&Products.product_name);
    printf("\n\tEnter the PRICE of the product(for one quantity):\t");
    scanf("%f",&Products.product_price);
    printf("\n\tEnter the QUANTITY of the product:\t");
    scanf("%d",&Products.product_quantity);
    Sale.soldid=Products.product_id;
    strcpy(Sale.soldname,Products.product_name);
    Sale.soldquantity=0;
    Sale.soldcost=0;
    //writing product to file
    fwrite(&Products,sizeof(Products),1,fptr);
    fclose(fptr);
    fwrite(&Sale,sizeof(Sale),1,fptr1);
    fclose(fptr1);
    printf("\n\tProduct successfully added to the Inventory\n");
    viewinventory();
}
//View inventory function
int viewinventory()
{
    fptr = fopen("Inventory.dat","rb");
    if(fptr==NULL)
        return 0;
    else
        return 1;
    if(fptr==NULL)
    {
       printf("ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go add Products in ADD PRODUCTS SECTION\n");
       printf("\n\n\n Program is closing ....");
       fclose(fptr);
       //getch();
       exit(0);
    }
    printf("\n================================================\n");
    printf(" ID\tName\tQuantity\tPrice(for each)\n");
    printf("================================================\n");
    while(fread(&Products,sizeof(Products),1,fptr)>0)
    {   
        printf(" %d\t",Products.product_id);
        printf("%s\t",Products.product_name);
        printf("%d\t\t",Products.product_quantity);
        printf("%.2f\n\n",Products.product_price);
    }
    fclose(fptr);
    //getch();
    return 0;
}

//Take order function
void takeorder()
{
    int n,found=0;
    static int bilnum=0;
    int choice=0;
    FILE *fptr1, *fptr2;
    viewinventory();
    
    fptr1= fopen("Customer.txt","wb");
    if(fptr1==NULL)
    {
       printf("ERROR!!! FILE COULD NOT BE OPEN\n\n\n");
       printf("\n\n\n Program is closing ....");
       fclose(fptr1);
       //getch();
       exit(0);
    }
    Bill.totalcost=0;
    fprintf(fptr1,"\n---------------------------------------------------------\n");
    fprintf(fptr1," PRO-ID NAME QUANTITY COST\n");
    fprintf(fptr1,"---------------------------------------------------------\n");
    do {
        fptr = fopen("Inventory.dat","rb+");
        fptr2 = fopen("Salesrecord.dat","rb+");
        printf("\nEnter item ID:\t");
        scanf("%d",&Bill.pro_id);
        printf("\nEnter quantity:\t");
        scanf("%d",&Bill.customer_quantity);

        while(fread(&Products,sizeof(Products),1,fptr)>0)
        {
            if((Bill.pro_id==Products.product_id)&&(Products.product_quantity>0))
            {   
                fprintf(fptr1,"\t%d",Bill.pro_id);
                strcpy(Bill.customer_product,Products.product_name);
                fprintf(fptr1,"\t%s",Bill.customer_product);
                fprintf(fptr1,"\t%d",Bill.customer_quantity);
                Bill.ind_cost = Bill.customer_quantity * Products.product_price;
                fprintf(fptr1,"\t%.2f\n",Bill.ind_cost);
                Bill.totalcost=Bill.totalcost+ Bill.ind_cost;
                printf("\n\tItem added to Bill\n");
                Products.product_quantity = Products.product_quantity - Bill.customer_quantity;
                fseek(fptr,-sizeof(Products),1);
                fwrite(&Products,sizeof(Products),1,fptr);
                while(fread(&Sale,sizeof(Sale),1,fptr2)>0)
                {
                    if (Bill.pro_id==Sale.soldid)
                    {
                        Sale.soldquantity=Sale.soldquantity+Bill.customer_quantity;
                        Sale.soldcost=Sale.soldcost+Bill.ind_cost;
                        fseek(fptr2,-sizeof(Sale),1);
                        fwrite(&Sale,sizeof(Sale),1,fptr2);
                        break;
                    }
                    
                }
                fclose(fptr2);
                found=1;
                printf("\n\tDo you want to add more Items[1/0]:\n");
                scanf("%d",&choice);
                break;
            }
            else if(Products.product_quantity<0)
            {
                printf("\nSorry! Either the there is no such ID or the quantity is zero\n");
                fclose(fptr2);
                found=1;
                printf("\n\tDo you want to add more Items[1/0]:\n");
                scanf("%d",&choice);
                break;
            }
            
        }
        fclose(fptr);
    }while(choice!=0);
    if(found==0)
    {
        printf("\n\t Sorry!! There is some issue\n");
        exit(0);
    }
    fprintf(fptr1,"---------------------------------------------------------\n");
    fprintf(fptr1,"\tTotal Cost : \t %.2f\n",Bill.totalcost);
    rewind(fptr1);
    printf("\n\tEnter the customer name\t:");
    scanf("%s",Bill.customer_name);
    bilnum+=1;
    Bill.bill_number=bilnum;
    fprintf(fptr1,"\tCUSTOMER NAME: %s\n",Bill.customer_name);
    fprintf(fptr1,"\tBILL NUMBER: %d\n",Bill.bill_number);
    fclose(fptr1);
    //getch();
}

//Records Page
void records()
{
    int choice;
    do{
    printf("\n\tYOU ARE IN RECORDS PAGE\n");
    printf("\n1. SALES RECORD\n");
    printf("\n2.CLEAR SALES RECORD\n");
    printf("\n3.SPREADSHEET RECORD\n");
    printf("\n4. BACK TO MAIN PAGE\n");
    printf("\t Enter your choice:\t");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1: salesrecord();
            break;
    case 2: Clearsalesrecord();
            break;
    case 3: Spreadsheet();
            break;                       
    case 4:break;
    default: printf("\n\tInvalid choice\n");
        break;
    }
    }while(choice!=4);
}

void salesrecord()
{
    fptr = fopen("Salesrecord.dat","rb");
    if(fptr==NULL)
    {
       printf("ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go add Products in ADD PRODUCTS SECTION\n");
       printf("\n\n\n Program is closing ....");
       fclose(fptr);
       //getch();
       exit(0);
    }
    printf("\n================================================\n");
    printf(" ID\tName\tQuantity\tSold(for each)\n");
    printf("================================================\n");
    while(fread(&Sale,sizeof(Sale),1,fptr)>0)
    {   
        printf(" %d\t",Sale.soldid);
        printf("%s\t",Sale.soldname);
        printf("%d\t\t",Sale.soldquantity);
        printf("%.2f\n\n",Sale.soldcost);
    }
    fclose(fptr);
    //getch();
}
//Clear sales record
void Clearsalesrecord()
{
    //fptr = fopen("Salesrecord.dat","w");
    FILE *fptr1 = fopen("Inventory.dat","rb");
    if(loginpage("LTTS","104694"))
    {
        fptr = fopen("Salesrecord.dat","w");
        while(fread(&Products,sizeof(Products),1,fptr1)>0)
        {
            Sale.soldid=Products.product_id;
            strcpy(Sale.soldname,Products.product_name);
            Sale.soldcost=0;
            Sale.soldquantity=0;
            fwrite(&Sale,sizeof(Sale),1,fptr);
        }
        printf("\n\tRECORD SUCCESSFULLY CLEARED\n");
    }
    else 
    {
        printf("\nInvalid Username or Password!! You are not allowed to clear sales record\n");
    } 
    fclose(fptr);
    fclose(fptr1);
    //getch();
}

void Spreadsheet()
{
    float income=0;
    FILE *fptr1,*fptr2;
    fptr = fopen("Dailyrec.csv","w");
    fptr1 = fopen("Inventory.dat","rb");
    fptr2 = fopen("Salesrecord.dat","rb");
    if(fptr==NULL||fptr1==NULL||fptr2==NULL)
    {
        printf("\nFie cannot be opened\n");
        exit(0);
    }
    fprintf(fptr,"ID,NAME,LEFT,PRICE,SOLD,CASH\n");
    while (fread(&Products,sizeof(Products),1,fptr1))
    {
            fread(&Sale,sizeof(Sale),1,fptr2);
            fprintf(fptr,"%d,",Products.product_id);
            fprintf(fptr,"%s,",Products.product_name);
            fprintf(fptr,"%d,",Products.product_quantity);
            fprintf(fptr,"%f,",Products.product_price);
            fprintf(fptr,"%d,",Sale.soldquantity);
            fprintf(fptr,"%.2f\n",Sale.soldcost);
            income=income+Sale.soldcost;
    }
    fprintf(fptr,"\n , , ,TOTAL,Rs.,%.2f",income);
    fclose(fptr1);
    fclose(fptr2);
    fclose(fptr);
    fptr=NULL;
    fptr1=NULL;
    fptr2=NULL;
    printf("\n\tSuccessfully Done\n");
    //getch();
}
void aboutltts()
{
    printf("\n\t\t\tHi.. glad that you want to know about us..\n");
    printf("\t\t\tLTTS cafeteria is established in 1938\n");
    printf("With 25+ branches and 16000+ employes LTTS cafteria is one the top restaurants in the world\n");
    printf("\t\t\tLTTS Presents you the most popular Indian food with\n");
    printf("\thuge collection of Vegetarian and Non-vegetarian recipes from India and around the world.\n");
    printf("\t\tWe provide you with easy and delicious recipes\n");
    printf("\t\twith simple, step-by-step instructions for a hassle-free cooking experience\n");
    printf("\t\t\t\tWe serve both Veg and Non-Veg food\n");
    //getch();
}
