CS 5115 : Programming for Graduate Studies
Programming Assignment 4 : TCP/IP Client-Server Interaction
--------------------------------
Outline: 
1. Project Objectives
	->Design and implement a simple TCP/IP server and client program.	
	->Server reads data sent by the client, converts bytes to integers, and prints them.
2. Server Program (TCP_server.c)
	->Description
	->Error Handling
3. Client Program (TCP_client.c)
	->Description
	->Error Handling
4. Execution Guide
	->Prerequisites
	->Compilation
	->Execution
5. Testing Procedures
	->Test 1: Server Not Available
	->Test 2: Client File Open Error
	->Test 3: Successful Execution
6. Testing with Multiple Clients Concurrently
	->Compile Programs
	->Run Server
	->Run Multiple Clients
	->Verify
-------------------------------------------------------------------------------------------


Project Objectives:
You will design and implement a simple TCP/IP server and client program. The server should read data sent by the client, convert the bytes to integers, and print them. Your task is to create both the server and client programs.

Requirement defined: HW4_Fall24_CS5115prog.pdf
------------------------------------------------------------------------------------------------------------------

Server Program:
Filename: TCP_server.c

Description: 
This program sets up a TCP server that listens for incoming connections on port 8080. It reads hexadecimal strings sent by clients, converts them to integers, and prints the results along with the current time.

Error Handling:
Socket Creation: Checks if the socket is created successfully.
Binding: Ensures the socket is bound to the specified port.
Listening: Verifies the server is listening for incoming connections.
Accepting Connections: Handles errors during the acceptance of client connections.
Reading Data: Checks for errors while reading data from the client.
-------------------------------------------------------------------------------------------------------------------

Client Program:
Filename: TCP_client.c

Description: 
This program connects to a TCP server on port 8080, reads hexadecimal strings from a file (hw4input.txt), and sends them to the server. It prints the current time and the data sent.

Error Handling:
Socket Creation: Checks if the socket is created successfully.
Address Conversion: Ensures the IP address is valid and supported.
Connecting to Server: Handles errors during the connection to the server.
File Opening: Verifies the file is opened successfully.
Sending Data: Checks for errors while sending data to the server.
-------------------------------------------------------------------------------------------------------------------

Execution Guide: 
To execute the server and client programs, follow these steps below.

Prerequisites:
Ensure you have a C compiler installed (e.g., gcc).
Both server and client programs should be in the same directory.
Create a file named hw4input.txt with hexadecimal strings for the client to send.
---------------------------------------------------------

Compilation:
Compile the Server Program:
	$ gcc -o server TCP_server.c
Compile the Client Program:
	$ gcc -o client TCP_client.c
-----------------------------------------------------------

Execution:
Start the Server:
Open a terminal and run the server program:
	$ ./server
The server will start listening on port 8080.

Run the Client:
Open another terminal and run the client program:
	$ ./client

The client will read from hw4input.txt and send the data to the server.
---------------------------------------------------------------------------------------------------------------------

Testing Procedures:

1. Server Not Available -> test1.client.ts
Test: Start the client without starting the server.
Expected Result: The client should display a “Connection failed” error.
Documentation: The client handles the error gracefully and exits.
Console: 	
	┌──(aruntotad㉿totad)-[~/Desktop/PA4_CS5115]
	└─$ gcc -o client TCP_Client.c
		                                                                                            
	┌──(aruntotad㉿totad)-[~/Desktop/PA4_CS5115]
	└─$ ./client                  
	Connection failed: Connection refused
#############################################################################################

2. Client unable to send : File Open Error: -> test2.client.ts
Test: Run the client with a non-existent file.
Expected Result: The client should display a “File open error”.
Documentation: The client handles the error gracefully and exits.
Console:
	┌──(aruntotad㉿totad)-[~/Desktop/PA4_CS5115]
	└─$ gcc -o client TCP_Client.c
		                                                                                            
	┌──(aruntotad㉿totad)-[~/Desktop/PA4_CS5115]
	└─$ ./client                  
	File open error: No such file or directory
############################################################################################

3. Successful execution -> 
Console: test3.client.ts
	┌──(aruntotad㉿totad)-[~/Desktop/PA4_CS5115]
	└─$ gcc -o client TCP_Client.c
		                                                                                            
	┌──(aruntotad㉿totad)-[~/Desktop/PA4_CS5115]
	└─$ ./client                  
	Current time: Wed Nov 13 13:05:31 2024
	Sent: 1a2b3c4d5e6f

	Current time: Wed Nov 13 13:05:41 2024
	Sent: aabbccddeeff

	Current time: Wed Nov 13 13:05:51 2024
	Sent: 102030405060

	Current time: Wed Nov 13 13:06:01 2024
	Sent: f1e2d3c4b5a6

	Current time: Wed Nov 13 13:06:11 2024
	Sent: 112233445566

	Current time: Wed Nov 13 13:06:21 2024
	Sent: a1b2c3d4e5f6

	Current time: Wed Nov 13 13:06:31 2024
	Sent: abcdef012345

	Current time: Wed Nov 13 13:06:41 2024
	Sent: 9876543210abc

	Current time: Wed Nov 13 13:06:51 2024
	Sent: 112233445566778899

	Current time: Wed Nov 13 13:07:01 2024
	Sent: deadbeefcafe

	Current time: Wed Nov 13 13:07:11 2024
	Sent: 001122334455

	Current time: Wed Nov 13 13:07:21 2024
	Sent: fedcba987654
________________________________________________________________________________

Console: test3.server.ts 
	┌──(aruntotad㉿totad)-[~/Desktop/PA4_CS5115]
	└─$ ./server                  
	Server listening on port 8080
	Current time: Wed Nov 13 13:05:31 2024
	Received hex: 1a2b3c4d5e6f
	Converted to integer: 28772997619311

	Current time: Wed Nov 13 13:05:41 2024
	Received hex: aabbccddeeff
	Converted to integer: 187723572702975

	Current time: Wed Nov 13 13:05:51 2024
	Received hex: 102030405060
	Converted to integer: 17730434519136

	Current time: Wed Nov 13 13:06:01 2024
	Received hex: f1e2d3c4b5a6
	Converted to integer: 265956517787046

	Current time: Wed Nov 13 13:06:11 2024
	Received hex: 112233445566
	Converted to integer: 18838586676582

	Current time: Wed Nov 13 13:06:21 2024
	Received hex: a1b2c3d4e5f6
	Converted to integer: 177789161760246

	Current time: Wed Nov 13 13:06:31 2024
	Received hex: abcdef012345
	Converted to integer: 188900966474565

	Current time: Wed Nov 13 13:06:41 2024
	Received hex: 9876543210abc
	Converted to integer: 2682143778081468

	Current time: Wed Nov 13 13:06:51 2024
	Received hex: 112233445566778899
	Converted to integer: 9223372036854775807

	Current time: Wed Nov 13 13:07:01 2024
	Received hex: deadbeefcafe
	Converted to integer: 244837814094590

	Current time: Wed Nov 13 13:07:11 2024
	Received hex: 001122334455
	Converted to integer: 73588229205

	Current time: Wed Nov 13 13:07:21 2024
	Received hex: fedcba987654
	Converted to integer: 280223976814164

--------------------------------------------------------------------------------------------------------------------

Testing with Multiple Clients Concurrently:

Compile the Programs:
	$ gcc -o server TCP_Server.c
	$ gcc -o client TCP_Client.c

Run the Server:
	$ ./server

Run Multiple Clients:
Open multiple terminals or use a script to run multiple clients concurrently:
	$gnome-terminal -- bash -c "./client; exec bash"
	$gnome-terminal -- bash -c "./client; exec bash"
	$gnome-terminal -- bash -c "./client; exec bash"

Verify:
Ensure the server correctly receives and processes data from all clients.
--------------------------------------------------------------------------------------------------------------------
