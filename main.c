#include"dependencies.h"

void main(){

	sort();
	load_file();
	choice_taker(1);
}


//LOADS THE FILE INTO GLOBAL STORAGE VARIABLE
void load_file(){

	char buff[MAX_LENGTH];
	FILE *main_file;
	main_file = fopen("list.txt","r");
	int i=0;
	if(main_file==NULL){
		printf("\tError in creating file");
		return;
	}//returns error is is error opening the file in read mode

	while(fgets(buff,MAX_LENGTH,main_file)){
		strcpy(storage[i],buff);
		i++;
	}
	fclose(main_file);
	return;

}

//{(C)REATE} ADDS TO THE NEW DATA
void add_to_list_file(){

	load_file();
	char deciding;
	FILE* main_file; //FILE* defines a pointer to the predefined FILE struct in the stdio library
	char item_name[MAX_LENGTH],priority;

	main_file = fopen("list.txt","a");//fopen() opens a file in the memory and returns the address of it.
	
	if(main_file == NULL){
		printf("\tError opening file!!\n"); return;} //returns with error message in stdout if the file is mislabelled or non-existent.
	else	
	{
	printf("\tWhat is the item?:\t");	
	
	gets(item_name);//gets() takes input from the stdin until a \n character is obtained.

	printf("\tWhat is the priority of the item to get?[#>*>-]: ");
	scanf(" %c",&priority);

	//fprintf(filepointer,"values/identifier",variable);

	fprintf(main_file,"%c|%s\n",priority,item_name);
	//load_file() loads the global variable with value from the list.txt
	load_file();
	printf("\tWould you like to continue(Y/N)?\n");
	scanf(" %c",&deciding);
	}
	fclose(main_file);
	sort();
	if(deciding=='Y' || deciding == 'y'){
		label();
		choice_taker(0);
	}	
	else{
		return;
	}

}
//{(R)EAD} LISTS THE EXISTING DATA

void read_list_from_file(){	
	char deciding;
	sort();
	load_file();
	int i=0;
	printf("\n");
	//iterages the storage array until the storage array is show to be empty(i.e storage[i]<=0)
	while( strlen(storage[i])>0){
		printf("<%d>%s",i+1,storage[i]);
		i++;	
	}
	printf("\tWould you like to continue(Y/N)?\n");
	//Extra space " " between the format specifier in scanf removes the \n character that was left in the input buffer when an integer was taken as an input/
	
	scanf(" %c",&deciding);
		if(deciding=='Y' || deciding == 'y'){
		label();
		choice_taker(0);
	}	
	else{
		return;
	}
}


//{(D)ELETE} DELETES FROM THE EXISTING DATA
void delete_from_file(){

	char deciding;
	sort();
	char temp_storage[MAX_SIZE][MAX_LENGTH];
	FILE* mainFile;
	mainFile = fopen("list.txt","w");
	char charBuff,strBuff[MAX_SIZE];
	int i=0,c,j;
	system("clear");
		
	while(strlen(storage[i])>0){
		printf("\n<%d>%s",i+1,storage[i]);
		i++;
	}

	printf("\tWhat index of value would you like to remove?:\n");
	scanf(" %d",&c);
	c-=1;
	i=0;
	while(strlen(storage[i])>0){//while the storage[i] >0 implies while the storage variable(ie 2D matrix of characters) has a string in it
		if( i == c ){
			i++;
			continue;	
		
		}
		strcpy(temp_storage[i],storage[i]); //copies into strings of storage in to temp_storage(a string buffer)
		fprintf(mainFile,"%s",storage[i]);//prints the content of storage into mainFile
		i++;
	}
	clear_array(i);
	sort();	
	fclose(mainFile);//always close a file before returning a function/
	system("clear");
	printf("\tWould you like to continue(Y/N)?\n");
	scanf(" %c",&deciding);


	if(deciding=='Y' || deciding == 'y'){
		label();
		choice_taker(0);
	}	
	else{
		return;
	}
}


void choice_taker(int first_visit){
	
	char conf;
	int choice=1;
	if(first_visit){
	label();
	}
	printf("\t\t[1]List from the list.\n");	
	printf("\t\t[2]Create new item into the list.\n");
	printf("\t\t[3]Delete existing item from the list.\n");
	printf("\t\t[4]Clear all the data from the file.\n");
	printf("\t\t[5]Exit from program.\n");		
	printf("\t\t[6]Print the list.\n");
	scanf("%d",&choice);
	getchar();
	label();
	scroll_renderer(choice);
	printf("\tPress enter to confirm or anything else to redirect back:\n");

	conf = getchar();
	if(conf=='\n'){
	function_caller(choice);
	}
	else
	{
		choice_taker(1);
	}
}


void label(){
	system("clear");
	printf("\t\t\t\t-------------------------------\n");
	printf("\n");
	printf("\t\t\t\t   GROCERY ITEM LIST MANAGER   \n");		
	printf("\n");
	printf("\t\t\t\t-------------------------------\n");
	return;
}

void sort(){
	int i,j;
	load_file();
	FILE* main_file;
	char strBuff[MAX_LENGTH];
	main_file = fopen("list.txt","w");
	
	i=0;
	j=1;
	while(strlen(storage[i])>0){
		while(strlen(storage[j])>0){
			if(strcmp(storage[i],storage[j]) > 0){						 
				strcpy(strBuff,storage[i]);
				strcpy(storage[i],storage[j]);
				strcpy(storage[j],strBuff);
			}
			j++;	
		}
		i++;
		j=i+1;
	}
	i=0;
	while(strlen(storage[i])>0){
		fprintf(main_file,"%s",storage[i]);
		i++;
	}
//LOAD THE NEW SORTED VALUES
	load_file();	
	fclose(main_file);
	return;
}



void clear_all(){
	int i=0;
	FILE* mainFile;
	char deciding;
	mainFile = fopen("list.txt","w");//opens the new file in "w" mode erasing all the data.
	fclose(mainFile);
	
	while(i<=MAX_SIZE){
		strcpy(storage[i],"");i++;
	}

	printf("\t\tWould you like to continue(Y/N)?\n");
	scanf(" %c",&deciding);


	if(deciding=='Y' || deciding == 'y'){
		label();
		choice_taker(0);
	}	
	else{
		return;
	}

}
void clear_array(int j){
	int i=0;
	while(j>=i){
		strcpy(storage[i],"");
		i++;
	}//clears the global variable before and upto the value that is to be deleted.

}

void function_caller(int x){
	
	if(x==1 ){
		system("clear");	
		read_list_from_file();
		return;
	}
	if(x==2){
		
		system("clear");	
		add_to_list_file();
		return;
	}

	if(x==3){
		
		system("clear");	
		delete_from_file();
		return;
	}
		
	if (x==4){ 
		system("clear");	
		clear_all();
		return;
	}
	 if(x==5){
		system("clear");	
		return;
	 }

	if(x==6){
		system("clear");
		print_slip();
		return;
	}

	}


void scroll_renderer(int choice){
	switch(choice){
	
		case 1:
	printf("\t\t->[1]List from the list.\n");	
	printf("\t\t[2]Create new item into the list.\n");
	printf("\t\t[3]Delete existing item from the list.\n");
	printf("\t\t[4]Clear all the data from the file.\n");
	printf("\t\t[5]Exit from program.\n");	

	printf("\t\t[6]Print the list.\n");
	return;
	break;
		case 2:
	printf("\t\t[1]List from the list.\n");	
	printf("\t\t->[2]Create new item into the list.\n");
	printf("\t\t[3]Delete existing item from the list.\n");
	printf("\t\t[4]Clear all the data from the file.\n");
	printf("\t\t[5]Exit from program.\n");	
	printf("\t\t[6]Print the list.\n");
	return;	
	break;
		case 3:
	printf("\t\t[1]List from the list.\n");	
	printf("\t\t[2]Create new item into the list.\n");
	printf("\t\t->[3]Delete existing item from the list.\n");
	printf("\t\t[4]Clear all the data from the file.\n");
	printf("\t\t[5]Exit from program.\n");	
	printf("\t\t[6]Print the list.\n");
	return;
	break;
		case 4:
	printf("\t\t[1]List from the list.\n");	
	printf("\t\t[2]Create new item into the list.\n");
	printf("\t\t[3]Delete existing item from the list.\n");
	printf("\t\t->[4]Clear all the data from the file.\n");
	printf("\t\t[5]Exit from program.\n");	
	printf("\t\t[6]Print the list.\n");
	return;
		case 5:
	printf("\t\t[1]List from the list.\n");	
	printf("\t\t[2]Create new item into the list.\n");
	printf("\t\t[3]Delete existing item from the list.\n");
	printf("\t\t[4]Clear all the data from the file.\n");
	printf("\t\t->[5]Exit from program.\n");	
	printf("\t\t[6]Print the list.\n");
	return;


		case 6:
	printf("\t\t[1]List from the list.\n");	
	printf("\t\t[2]Create new item into the list.\n");
	printf("\t\t[3]Delete existing item from the list.\n");
	printf("\t\t[4]Clear all the data from the file.\n");
	printf("\t\t[5]Exit from program.\n");	
	printf("\t\t->[6]Print the list.\n");
	return;
		default:
	choice_taker(1);	
	break;
	}
}


void print_slip(){
	
	int i=0;
	FILE *new_file;

	new_file = fopen("lists/list.txt","w");

	load_file();	
  fprintf(new_file,  "\n\n\n||   |                                                                                                ||    \n");
    fprintf(new_file,"  || |     ...   ... ...  ... ..       ... . ... ..    ...     ....    ....  ... ..  .... ...     ||  ...   ....  .||.   ||\n");
    fprintf(new_file,"   ||    .|   |.  ||  ||   ||  .      || ||   ||  .  .|  .|. .|   .  .|...||  ||  .   |.  |       ||   ||  ||. .   ||\n");
    fprintf(new_file,"   ||    ||   ||  ||  ||   ||          |..    ||     ||   || ||      ||       ||        |.|       ||   ||  .  |..  ||    ||\n");
    fprintf(new_file,"  .||.    .|..|    |.. |. .||.        .|  |. .||.      |..|   | ...   .|...  .||.       ||       .||. .||. | ..|.  .||.\n");
   
    fprintf(new_file,"\n\n\t\t\t\t\t\t%s\t\t\n", __DATE__ );
	while(strlen(storage[i])>0){

		fprintf(new_file,"\n\t\t\t\t\t\t<%d>\t%s",i+1,storage[i]);	
		i++;
	}

	printf("\nYour list has been printed successfully.\n");
	clear_all();
	fclose(new_file);
	return;
}
