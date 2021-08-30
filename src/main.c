// Loading libraries
#include"mod/lib/pch.h"

// Defining modules macros (needed before including modules)
// RCP example
#define RCP_PRECOMPILE_HEADERS 1
#define RCP_AUTO_RECOMPILE 1

#define RCP_SOURCE_PATH "../build/compile-sources.bin"
#define RCP_HEADER_PATH "../build/compile-headers.bin"

// RSI macros
#define RSI_KEYBOARD_INPUT_FILE "/dev/input/by-path/platform-i8042-serio-0-event-kbd"
#define RSI_MOUSE_INPUT_FILE "/dev/input/mice"

// Including all modules (for demo purposes)
#include"mod/ext/ahl.h"
#include"mod/ext/ecl.h"
#include"mod/ext/rcp.h"
#include"mod/ext/rsi.h"
#include"mod/ext/soc.h"

// RSI function binding and buffer declaration
int key_buffer[256];
void key_callback(int key,int act){
	if(act==RSI_KEY_PRESSED) key_buffer[key]=1;
	if(act==RSI_KEY_RELEASE) key_buffer[key]=0;
}
void mouse_callback(int x,int y,int button[3]){
	printf("x=%d, y=%d, l=%d, m=%d, r=%d\n",x,y,button[0],button[1],button[2]);
}

// SOC data and function
void *item_data[65536]={(void*)20,(void*)10,"aaa"};
void item_function(){
	if(key_buffer[KEY_Q]){
		SOC_CHECKED_LOOP("unknown",			
			SOC_DATA_LOOP(soc_item_list[i].data,	
				if(soc_item_list[i].data[j]==(void*)10)	
				printf("%s\n","First and only item has type 'unknown' and contains '10' inside it's data array");
			)
		)
		
	}
}

// Random function for AHL example
void printHelloWorld(){
	printf("%s\n","Hello World from AHL !");
}

// Main function
int main(){
	// ECL example
	eclEvalFile("file-example.bin");
	
	// AHL example
	ahlUpdateBuffer("b8 ca 9b 04 08 ff e0 c3"); // Calls printHelloWorld()
	ahl_funcptr func=ahlAttribPointer(ahl_buffer);
	func();
	
	// Soc example
	SOC_ITEM object_instance;
	object_instance.type="unknown";
	*object_instance.data=*item_data;
	object_instance.func=item_function;
	socAddItem(object_instance);
	
	// RSI example
	rsiBindCallback(&key_callback,&mouse_callback);
	while(!key_buffer[KEY_ESC]){ // Exits on escape
		socUptItem(); // Updating soc items
		rsiPollEvents();
	}
	
	// Deleting item with id 0 (the only one)
	socDelItem(0);
	
	return 1; // Terminated successfully
}
