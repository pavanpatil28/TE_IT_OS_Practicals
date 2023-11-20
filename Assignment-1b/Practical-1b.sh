# ASSIGNMENT NO-1(A)
# Write a program to handle student database with options given below
# 1)Create database
# 2)View database
# 3)Insert a record
# 4)Delete a record
# 5)Modify a record
# 6)Result of a particular student


clear 
CREATE()
{
	echo " >> Enter Name of the Address Book :: "
	read name
	
	result=`ls | grep $name | wc -w`
	
	if [ $result -gt 0 ]
	then
		echo " ---> Sorry File Already Exists !!! "
	else
		touch $name
		echo " ---> File Created Successfully !!! "
	fi
}


DISPLAY() 
{
	#echo "Enter the file you want to open"
	#read $name
	
	result=`ls | grep $name | wc -w`
	
	if [ $result -gt 0 ]
	then
		cat $name
	else
		echo " ---> File does not exists !!!"
	fi
}

INSERT()
{
	#echo "Enter the file you want to open"
	#read $name
	
	result=`ls | grep $name | wc -w`
	
	if [ $result -gt 0 ]
	then
		echo " >> Enter Your E-mail :: "
		read email
		len=`cat $name | grep $email | wc -w`
		if [ $len -gt 0 ]
		then 
			echo " ---> Record already Exists !!! "
		else
			echo " Enter First Name :: "
			read fname
			echo " Enter Last Name :: "
			read lname
			echo " Enter Mob-No :: "
			read mobno				
							
			record=`echo $fname $lname $email $mobno`
			
			echo $record >> $name # > -- override
			echo " ---> Record Inserted Successfully !!! "
		fi
	else
		echo " ---> File does not Exists !!! "
	fi
}

MODIFY()
{
	#echo "Enter the file you want to open"
	#read $name
	
	result=`ls | grep $name | wc -w`
	
	if [ $result -gt 0 ]
	then
		echo " >> Enter Your E-mail :: "
		read email
		len=`cat $name | grep $email | wc -w`
		if [ $len -gt 0 ]
		then 
			echo " Enter First Name :: "
			read fname
			echo " Enter Last Name :: "
			read lname
			echo " Enter Mob-No :: "
			read mobno	
			
			new=`echo $fname $lname $email $mobno`
			old=`cat $name | grep $email`
			
			echo " --> Old Record :: $old"
			echo " --> New Record :: $new"
			sed -i s/"$old"/"$new"/g $name
			echo " ---> Record Modified Successfully !!! "
		else
			echo " Enter First Name :: "
			read fname
			echo " Enter Last Name :: "
			read lname
			echo " Enter Mob-No :: "
			read mobno	
			
			record=`echo $fname $lname $email $mobno`
			
			echo $record >> $name # > -- override
			echo " ---> Record Inserted Successfully !!! "
		fi
	else
		echo " ---> File does not Exists !!! "
	fi
}

DELETE()
{
	#echo "Enter the file you want to open"
	#read $name
	
	result=`ls | grep $name | wc -w`
	
	if [ $result -gt 0 ]
	then
		echo " >> Enter Your E-mail :: "
		read email
		len=`cat $name | grep $email | wc -w`
		if [ $len -gt 0 ]
		then 
			old=`cat $name | grep $email`
			
			sed -i s/"$old"//g $name
			sed -i /^$/d $name
			echo " ---> Record Deleted Successfully !!! "
		else
			echo " ---> Record Not Found !!! "
		fi
	else
		echo " ---> File does not Exists !!! "
	fi
}

SEARCH()
{
	#echo "Enter the file you want to open"
	#read $name
	
	result=`ls | grep $name | wc -w`
	
	if [ $result -gt 0 ]
	then
		echo " >> Enter E-mail :: "
		read email
		len=`cat $name | grep $email | wc -w`
		if [ $len -gt 0 ]
		then 
			rec=`cat $name | grep $email`
			
			echo " ---> Record Found !!! "
			echo "$rec"
		else
			echo " ---> Record Not Found !!! "
		fi
	else
		echo " ---> File does not Exists !!! "
	fi
}
while [ true ]
do
	echo " <<<<< MENU >>>>> "
	echo " 1] Create. "
	echo " 2] Display. "
	echo " 3] Insert Record. "
	echo " 4] Modify Record. "
	echo " 5] Delete Record. "
	echo " 6] Search Record. "
	echo " 7] Exit. "
	
	echo " >> Enter Your Choice :: "
	read choice
	
	case $choice in
	
		1)CREATE ;;
		2)DISPLAY ;;
		3)INSERT ;;
		4)MODIFY ;;
		5)DELETE ;;
		6)SEARCH ;;
		7) exit ;;
		
		*) echo " ---> Wrong Choice !!! " ;;
		
	esac
done	
	
