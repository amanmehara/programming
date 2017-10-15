#!/bin/bash

echo "*********************************************************************************************************************************************";
echo "*                                                                                                                                           *";
echo "*                                                                                                                                           *";
echo "*                                                          UNINSTALL TRACKER                                                                *";
echo "*                                                                                                                                           *";
echo "*                                                                                                                                           *";
echo "*********************************************************************************************************************************************";

printf "\n";
t=0;
k=0;
echo -e `date`;
printf "\n";

echo -e "Press 1 if you want to send silent push notification or 2 to send custom message push notification:";
read value;
printf "\n";

if [ $value -eq 1 ]
then 
echo -e `php push1.php`;
printf "\n";
printf "\n";

echo -e "Successfull!! Notification sent.";
printf "\n";

  echo -e "Press 1 to give output text file path to get the tracking info else press 2 for default path:";
  read value1;
  printf "\n";
  if [ $value1 -eq 1 ]
  then 
  echo -e "You are here:"
  echo -e `pwd`;
  echo -e "Now enter the path of your file:";
  read f1;
     if [ -f $f1 ]
     then
     t=`grep -o "NotRegistered" "${f1}"|wc -l`
     echo -e "No. of users who uninstalled our app: $t";
     k=`grep -o "InvalidRegistration" "${f1}"|wc -l`;
     echo -e "No. of wrong/not valid GCM ID provided: $k";
     printf "\n";

     else
     echo -e "File does not exists.. Either You made a mistake or Aliens erased the file.. RUN FOR YOUR LIFE!!!"
     printf "\n";
     fi



  elif [ $value1 -eq 2 ]
  then
  t=`grep -o "NotRegistered" "output1.txt"|wc -l`
  echo -e "No. of users who uninstalled our app: $t";
  k=`grep -o "InvalidRegistration" "output1.txt"|wc -l`;
  echo -e "No. of wrong/not valid GCM ID provided: $k";
  printf "\n";

  else
  echo -e "Wrong input!! Program exiting..";
  fi

elif [ $value -eq 2 ]
then
echo -e `php push1.php`;
printf "\n";
printf "\n";
echo -e "We have sent the push notification with the message provided in script.";
echo -e "And to add custom message from here, We need Kryptonite so that we can defeat Superman and take back our servers!!"
echo -e "We are adding new functionalities. Check back later!!";

else
echo -e "Wrong input!! Program exiting..";
fi

