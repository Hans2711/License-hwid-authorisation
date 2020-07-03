# License hwid authorisation
 builds a fresh version of the program for every Token with varible lengths
 c++
 
 Notice:
 - You need to have the folder in Your documents it prop wont work because your directory may be located somewhere else (look in the build.lnk for that)
 - You need to have visual studio and the dev tools installed 2019 is recommended (but if you want to use older versions you can change the directory in build.lnk too)
 - Make sure that your mysql database looks the same as in the picture db.png(db name = Tokens)
 - Make sure to have installed the Mysql Server 8.0 and the Mysql Connector for c++ 1.1.3 
 - Please notice that this kind of connecting to a mysql server is not very secure because without proper protection dumping the login credentials or sql injection attacks are common.(But with some minor thweaks and a proper obfuscation and packing it should be fine)
 - Im sorry that there are no comments in the code.
 - the Generator always has to be in the home directory even tho it doesnt build to that directory.
 - If add to the Generator code so taht he safes those files somewhere else with a random name you can speed up the process a lot.
 