#include "Visualizer.h"

int main() {

	Visualizer visualizer;

	while (visualizer.running()) {
		visualizer.update();
		visualizer.render();
	}

	return 0;
}