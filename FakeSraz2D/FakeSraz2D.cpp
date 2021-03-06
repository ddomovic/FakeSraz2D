// FakeSraz2D.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <GL/glut.h>
#include <time.h>
#include "WindowData.h"
#include "Game.h"
#include "GameState.h"

WindowData* window_data;
Game *game;

void display_f() {

	glClearColor(0.0, 0.0, 0.0, 1.0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glLineWidth(1.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	//glTranslatef(window_data->get_width()/2.0, window_data->get_height()/2.0, 0);

	game->render_scene();
	
	glFlush();
}

void reshape_f(int w, int h) {
	window_data->set_width(w);
	window_data->set_height(h);

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(1.0);
	glColor3f(0.0f, 0.0f, 0.0f);
}

void mouse_f(int button, int state, int x, int y) {
	game->get_current_state()->mouse_functions(button, state, x, window_data->get_height() - y);
}

void keyboard_f(unsigned char key, int x, int y) {
	game->get_current_state()->keyboard_functions(key, x, y);
}

int main(int argc, char *argv[]) {

	srand(time(NULL));
	window_data = new WindowData(800, 600);
	game = new Game(window_data);
	game->start_game();
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(window_data->get_width(), window_data->get_height());
	glutInitWindowPosition(0, 0);
	glutInit(&argc, argv);

	window_data->set_window(glutCreateWindow("FakeSRAZ 2D"));
	glutReshapeFunc(reshape_f);
	glutDisplayFunc(display_f);
	glutIdleFunc(display_f);
	glutMouseFunc(mouse_f);
	glutKeyboardFunc(keyboard_f);
	glutMainLoop();

    return 0;
}

