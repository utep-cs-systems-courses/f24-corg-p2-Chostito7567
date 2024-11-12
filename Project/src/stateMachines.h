#ifndef stateMachine_included
#define stateMachine_included

// Function prototypes for handling LED updates and button presses
void state_advance();
char toggle_red();
char toggle_green();
char toggle_red_green();

// New function to handle button presses and play jingles
void handle_button_press(char button);

#endif // stateMachine_included
