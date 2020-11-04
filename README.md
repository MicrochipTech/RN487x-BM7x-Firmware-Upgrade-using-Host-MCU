# RN487x-BM7x-Firmware-Upgrade-using-Host-MCU

## Introduction
The general firmware update process in the RN4870/1 and BM70/71 PICtail board is carried out using an isupdate flashing tool. The instruction guide for the RN and BM devices discusses in detail about the firmware flashing using the system based flashing tool. Based on Microchip’s continuous improvement policy we are focused on collecting the feedback from the customers, to fulfill the field requirements to make the product more reliable to the end users. Taking into consideration about few practical requirements that demand for an embedded application to execute firmware update for these devices, we have developed an alternative solution to execute firmware update for the controller devices.

   The alternative approach is designed to achieve the same task using an embedded application that execute the firmware update on the RN4870/1 and BM70/71 PICtail board is by using the host MCU.  The embedded application implements the firmware update protocol using the Host Controller interface. This document discusses in detail about the application execution and step by steps procedure to achieve the firmware update via the host MCU using UART based device firmware update protocol.
Microchip releases periodic updates to the application firmware to include new features and fix any bugs reported in previous release. These updates are provided with a release note along with the firmware files in the official webpage.

## Updating PICtail Firmware via tool 
Generally, the Firmware for the RN4870/71 PICtail can be updated using a PC Tool isupdate.exe over the USB port. The latest RN4870/71 firmware images and the isupdate.exe tool are available from the product web page at www.microchip.com/RN4870.

To update the firmware on the RN4870 PICtail, perform the following steps:

1.  Download the firmware zip file from the product web page and extract the contents.
      The zip file contains the isupdate.exe utility and a folder including the firmware images.
2. Connect the PICtail to the host PC using the micro USB cable.
3. Verify that SW7 is set to ON position.
4. Press SW5 Reset button and verify that LED1 is showing a non-flashing blue that
     indicates the RN487x module is in programming mode.
5. Launch the isupdate.exe application 
      - Select the COM port used by the PICtail board
      - Verify that other settings (baud, memory type, and address) 
6. Click the Connect button.
7. Update the firmware.
 
<p align="center">
<img src="https://user-images.githubusercontent.com/57740485/98047569-23b2bd00-1e52-11eb-86e9-01f3e4812eef.png" width=480>
</p>


# Firmware update using host MCU    

  ## Host Controller Interface
       
   The host and the controller communicate using the Host Controller Interface (HCI) protocol. This protocol is based on commands and events, i.e., the host sends (acknowledged) commands to the controller, and the controller uses events to notify the host. The HCI protocol can use different physical transports such as UART, SPI, and USB. The types of packets used are HCI command packet, HCI flash/data packets, HCI event response. 
   
   ## Memory programming
  
   The firmware update protocol follows the below described steps to access the memory of the device and execute the firmware update procedure. 
1.	Enter memory programming Mode: This step involves setting the module into the Flash programming mode. This is primarily achieved by setting the P2_0 pin to ‘0’ via hardware. Once entered, in the next subsequent steps, the host uses the UART transport layer to communicate the HCI Commands and HCI-ISDAP Flash commands to read, write or erase data in the memory
2.	Connect to the Flash: In this step, using the HCI commands, the external host can connect to the Flash in the device. The HCI event responses from the device, the user can verify that a successful connection is established with the Flash. 
3.	Flash operations: Using the HCI-ISDAP Flash commands, operations on Flash, such as, read, write and erase can be performed. 
4.	Disconnect from Flash: After the successful execution of flash memory operations, the external host needs to disconnect from the Flash by sending the relevant HCI commands to the device. The HCI event responses from the device can be used to verify the operation.


# Device Firmware Upgrade Process
## Entering Flash Programming Mode 

For memory programming, the minimum set of hardware connections needed to interface an external host to the BM70/71 is shown in figure below.  Making these hardware connections between the host and controller will allow a host to control the behavior (i.e. enter memory programming mode, enter test mode, communicate, and calibrate) of the module.

<p align="center">
<img src="https://user-images.githubusercontent.com/57740485/98063459-1c9da600-1e76-11eb-8384-366d4a6b4188.png" width=480>
</p>

   The controller operation, or mode, is determined by the level of a hardware pin, P2_0.  This pin is sampled when the RST_N pin goes active.  The RST_N signal must be active for the minimum time, to make sure the pin P2_0 logic level is latched into the IC correctly. Once the controller enters the applicable mode, communication over the UART interface becomes active. The data or protocol which is used to communicate between the host and controller is based on the mode the controller enters after a reset.   
At a high level, the memory programming mode is entered when pin P2_0 is latched by the controller at a logic level ‘0’.  
The application, or run mode, where general BTLE operation is available, is entered when pin P2_0 is latched by the controller at a logic level ‘1’. Table 1 below summarizes the use of the P2_0 pin.

<p align="center">
<img src="https://user-images.githubusercontent.com/57740485/98063851-fc221b80-1e76-11eb-857f-b605e77ca115.png" width=480>
</p>

## Commands
  To flash a new firmware revision into the Flash, the user needs to follow the command protocol. The protocol is based on the HCI command protocol outlined in the Bluetooth specification (www.bluetooth.org) volume 2, Part E, “Host Controller Interface Functional Specification” and Volume 4, Part A, “UART Transport Layer. 

   In general, the commands and responses for memory programming of the BM70/71 can be classified into three categories:
   
1. Command packets
* Connection Packet
* Disconnection Packet
2. Data Packet
* Erase Packet
* Read Packet 
*  Write Packet
3. Event Response Packet

# Connecting to the Flash
Connection command is used to create a connection to a remote device.  With regards to memory programming, the host uses this packet to establish a programming session with module.  The parameters in the packet are all set to zero, which indicates to the BM7x device, a programming connection is requested by the host.

-The HCI event responses from the device helps to verify that a successful connection is established with the Flash.
## Connection Packet
The host uses this command to establish a memory programming session with the module.

<p align="center">
<img src="https://user-images.githubusercontent.com/57740485/98064496-730be400-1e78-11eb-8167-6ebaf1833958.png" width=480>
</p>

## Connection Response format, module--->host
The module will respond to this command with an HCI Event Response 

<p align="center">
<img src="https://user-images.githubusercontent.com/57740485/98064616-b49c8f00-1e78-11eb-9b5b-b431f5c950c8.png" width=480>
</p>

## Connect Sequence
<p align="center">
<img src="https://user-images.githubusercontent.com/57740485/98064672-dac22f00-1e78-11eb-935c-72c22fbaf12b.png" width=480>
</p>

## Flash operations
After creating a programming session, the host next proceeds to execute flash operations using the HCI-ISDAP commands. 
## Data Packet 
The data packet can be used for the read, write and erase operations. Each operation uses a different command ID. 
<p align="center">
<img src="https://user-images.githubusercontent.com/57740485/98064850-51f7c300-1e79-11eb-92f0-8dd97785e045.png" width=480>
</p>

Command ID
* Erase - 0x0112
* Write - 0x0111
* Read - 0x0110


## Alternate data packet
This packet type is mainly used for writing continue operation.

<p align="center">
<img src="https://user-images.githubusercontent.com/57740485/98065116-de09ea80-1e79-11eb-8283-58f265e24968.png" width=480>
</p>

There are 3 type of write operation
* Initiate a write start command for the single write 
* Then uses the write continue packets to write data 
* Write stop can be used to stop the data write process 

<p align="center">
<img src="https://user-images.githubusercontent.com/57740485/98065769-3988a800-1e7b-11eb-9d70-01f0e39fe019.png" width=480>
</p>

Data will be sent in chunks; whose size gets added to packet length. If write continue operation follows this operation, then data will be appended after the data packet. The command ID session can be used to indicate the write continue operation. If this flag is set to a ‘1’, all subsequent write messages must be sent as Write 
## Response sequence, module--->host
The module will respond to the command with an HCI Event Response  

<p align="center">
<img src="https://user-images.githubusercontent.com/57740485/98065856-6f2d9100-1e7b-11eb-9ea4-dd626c637132.png" width=480>
</p>

## Disconnect 
After completing the Flash write process for flash the firmware files, the host needs to disconnect from the flash using the following command to end the programming session.  
## Disconnect packet

<p align="center">
<img src="https://user-images.githubusercontent.com/57740485/98065971-b156d280-1e7b-11eb-82d0-987e7d2b67bf.png" width=480>
</p>

## Programming Sequence
         		 The demo application implements the firmware update protocol by incorporating the data into packets which creates the data and command packets as described in the Host Controller Interface specifications. The event response from the device is then monitored by the host to check on the status notification send back from the device. The programming sequence of the demo application is described in below diagram

<p align="center">
<img src="https://user-images.githubusercontent.com/57740485/98066030-d77c7280-1e7b-11eb-9a9d-e4ba8d72d8bb.png" width=480>
</p>

## DFU Demo Application

* NOTE: The stand alone demo application is attached as a zipped folder in the repository. 

   The embedded MPlabx application is created that implements the firmware update in the RN4870/1 and BM70/71 PICtail board using the host MCU which follows the device firmware update protocol. The Explorer 16/32 development Board with the PIC32MX795F512L is used as the host MCU.
                
   The DFU Demo application project runs on supported Microchip development hardware noted in the Hardware Combinations section below. Pre-generated hex file for PIC32 ‘DFU_Demo.X.production.hex’ is available in the ‘\Applications\DFU_Demo\Precompiled_HEX’ folder.

<p align="center">
<img src="https://user-images.githubusercontent.com/57740485/98066159-262a0c80-1e7c-11eb-9da8-5f9a7f784042.png" width=480>
</p>

## Programming Demo
 
1) Plug-in the PIC Plug-In-Module (PIM) into the Explorer 16 Development Board.
- Note: On PIC32MX795F512L PIM, ensure that on jumpers J1 and J2 on the PIM, pins 2 and 3 are connected using a jumper to select the CAN configuration and all jumpers on J9 and J10 on the PIM are not connected. 

2)  Plug-in the BM70 PICtail Plus board into the Explorer Development Board with the BM7x module facing towards the PIC PIM as shown in Figure.
- Note: On the BM70 PICtail Plus board ensure that the following configuration is used
   - Power Source jumper block J1 is set to use PIC
   - Mode Switch SW7 is set to ON
   - USB UART jumper block has only TX and RX jumpers populated

3)  Connect the debug UART port to a PC terminal emulator program.
- Note: On the Explorer 16 Development Board, debug UART is available on the DB9 UART serial connector P1.

   Port - Select the COM port.\
   Baudrate	- 115200.\
   Data Bits - 8.\
   Parity - None.\
   Flow Control - None

4)  Provide power through the 9V power input port available on the Explorer Development Board.

5) Program the PIC32 with the ‘DFY_Demo.X.production.hex’ in the ‘Precompiled_HEX’ sub-directory using MPLAB REAL ICE tool.
	

6)  Alternately open the ‘DFU_Demo.X’ MPLABX workspace provided using the MPLABX IDE and compile and program or enter debug mode.
	Please refer to the following links for help on MPLABX project operations.
* Open a project: http://microchipdeveloper.com/mplabx:open-a-project
* Program a project: http://microchipdeveloper.com/mplabx:build-release
* Debug a project: http://microchipdeveloper.com/mplabx:build-debug

## Running Demo Application
     
1)	After setting up the hardware combination and programming the PIC using the above steps run the PIC program. 

2)	The program will start the updating the device firmware on the BM70 module. The sequence of operations of the DFU procedure can be observed on the debug UART.

3)	Wait until the firmware update completes and the debug UART indicates the completion of the update.

4)	Reboot the BM70 module for the updated firmware to start running. 

## Required Hardware
- BM70 PICtail Plus (BM-70-PICTAIL) 
- Explorer 16 Development Board (DM240001)
- PIC32MX795F512L Plug In Module (MA320003)

## Replacing the Firmware text file                         

* The default application will have the latest public released firmware (V1.40). 
* 	User can use the same application to flash the older or newer version of firmware my replacing the firmware file (rn487x.txt) that comes along with the application.

      - In the MPLAB project, The firmware file (rn487x.txt) is located at Host_DFU_RN-BM\PIC32_NVM\Applications\DFU_Demo 
      
* 	Ready to flash web released RN firmware is available in multiple files. 
* 	The firmware file is then converted into single test file, by using the below steps. 
     1) Merge multiple hex files to sing hex file
        - The multiple firmware files can be converted to single hex file using the Merging tool.
               -  The merging tool PreMPTool_new is located at: Host_DFU_RN-BM\Merging Tool
	       -  Select the multiple hex files as the input file and genarate single output file.
     2) To convert the HEX values to Binary file 
        The Atmel Studio has a avr-objcopy.exe utility. By using this tool we can convert the previously merged single HEX file to binary file
	
          1) Go to the location 
	       - C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\
          2) Open command prompt by typing "cmd" at the file path
          3) Execute the avr-objcopy.exe application in command prompt along with the parameters.
	         - avr-objcopy.exe -I ihex filename.HEX -O binary Hex2Binary.bin
          4) After successful execution, a Hex2Binary.bin file will get generated
  
          - The avr-objcopy.exe utility or any similar tool that achieve the similar functionality can be used to convert the HEX values to binary file. 
     3) Convert single binary file to a C array
        - The reference online tool can be used to convert the binary file to C array. 
        - Tool to Convert binary to c header file 
               - https://www.netzmal.de/bin2hex/
        - Copy the all the hex values and paste in a text file. 
        - Replace the existing text file in the project with this new text file. 

# Guidelines to the end users
                                  
-	The user needs to consider taking adequate backup of the existing firmware running on the controller. The demo application erases the current firmware and update it with the newly flashed firmware. 
-	Flashing the demo application to the host MCU will remove the existing application that resides in the MCU. The DFU Demo application showcases a proof-of-concept example that update the firmware on the BLE module. User needs to modify according to their requirement. 

- The application flow is designed in such a way that it writes the firmware content into the flash memory and read back the content to make sure the writing action is executed successfully. The CRC check is not implemented either at the host MCU side nor at the BLE controller part to check whether the firmware is corrupted. 


- Updating the existing firmware resides at the BLE controller will erase the configuration content (Pairing info, BLE name etc) just like the norm firmware update. The user needs to do the re-configuration again after the firmware update. 

- The user needs to take care of the integrity and responsibility to ensure security concerns. 
