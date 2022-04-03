#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include<conio.h>
/**
 * @file canteen.h
*/

/**
 * @note Structure Product to hold the product details
 * @note Each product details are stored in Inventory file from this structure
 * @note product_id holds the id for the product. This id is base for accessing the product
 * @note product_name holds the name of the product
 * @note product_price holds the price of the product per quantity
 * @note product_quantity holds the total quantity of the product
*/
struct
{
    int product_id;
    char product_name[8];
    float product_price;
    int product_quantity;
}Products;
/**
 * @note Structure Bill is for storing the customer information.This includes name,bill number,total cost
 * @note The customer details are stored in Customer file.This file acts as receipt to the Customer
 * @note bill_number holds the bill number of the customer
 * @note customer_name holds the name of the customer
 * @note pro_id holds the id of the product which the customer wish to order
 * @note customer_product holds the name of the product which the customer wish to order
 * @note customer_quantity holds the product quantity ordered by the customer (For current product only)
 * @note ind_cost holds the cost for a particular product ordered by the customer
 * @note totalcost holds the total amount payable by the customer
*/
struct 
{
    int bill_number;
    char customer_name[15];
    int pro_id;
    char customer_product[8];
    int customer_quantity;
    float ind_cost;
    float totalcost;
}Bill;

/**
 * @note Structure Sale is for record purpose. 
 * @note This structure holds the details of the product that are sold
 * @note soldid holds the oid of the product sold
 * @note soldname holds the name of the product sold
 * @note soldquantity holds the quantity of a product sold
 * @note soldcost holds the amount earned by selling the product 
 * @note  soldcost = quantity odered * cost of product perquantity
*/
struct 
{
    int soldid;
    char soldname[8];
    float soldcost;
    int soldquantity;
}Sale;

/**
 * @note loginpage is initial page to enter into the cafteria management
 * @note It'll ask you to enter the username and password
*/
int start(int);
int loginpage();

/**
 * @note takeorder function is responsible for taking the order
 * @note Requires id and the quantity
*/
void takeorder();

/**
 * @note Inventory can be managed.
 * @note Include adding products
 * @note Editing quantity and price
*/ 
void manageinventory();
//manage functions

/**
 * @note editprice function used to change the price for a particular product
 * @note This requires product id for which you want change the price
*/
int editprice();

/**
 * @note View the products which are in inventory file
*/
int viewinventory();

/**
 * @note To add products to the inventory
*/
void addproduct();
/**
 * @note addquantity function used to add quantity for a particular product
 * @note This requires product id for which you want add the quantity
*/
int addquantity();

//Records function
/**
 * @note Records of sales
*/
void records();
/**
 * @note Sales record of the products sold
 * @note The quantity of product sold
 * @note Total amount for the sold quantity
*/
void salesrecord();
/**
 * @note Clears the sales record
 * @note All the product quantity and cost is made to zero
*/
void Clearsalesrecord();
/**
 * @note The details of the products sold
 * @note Includes 
 * @note -> Quantity left in the inventory
 * @note -> Quantity sold
 * @note -> Cost of each product
 * @note -> Cash received for the sold quantity for a particular quantity
 * @note -> Total Income
*/
void Spreadsheet();

/**
 * @note About the LTTS cafteria
*/
void aboutltts();

/**
 * @note File pointer to point to different files
*/
FILE *fptr;
