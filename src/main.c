#include <pebble.h>
#include "test_window.h"
  

int main(void) {
    show_test_window();
    app_event_loop();
    hide_test_window();
}