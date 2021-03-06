#include <Game.h>

 // Uncomment for Part 2
 // ********************
bool flip = false;
int current = 1;
 // ********************

 //  Game::Game() : window(VideoMode(800, 600), "OpenGL"), primatives(2)

//Game::Game() : window(VideoMode(800, 600), "OpenGL")
Game::Game() : window(VideoMode(800, 600), "OpenGL"), primatives(2)
{
	 // Uncomment for Part 2
	 // ********************
	 index = glGenLists(primatives);
	 // ********************
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	glNewList(index, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
		glVertex3f(2.0, -2.0, -5.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 1, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.2, 0.0, -2.0);
		glVertex3f(-2.0, -2.0, -2.0);
		glVertex3f(2.0, -2.0, -2.0);
	}
	glEnd();
	glEndList();

	 // Uncomment for Part 2
	 // ********************
}

void Game::update()
{
	 // Uncomment for Part 2
	 // ********************
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!flip)
		{
			flip = true;
			current++;
			if (current > primatives)
			{
				current = 1;
			}
		}
		else
			flip = false;
	}

	if (flip)
	{
		rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
		//investigating glRotate
		//glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);

		//investigating glTranslate
		//glTranslatef(1.0f, 0.0f, 0.0f);

		//investigating glscalef
		//glScalef(1.0f, 1.0f, 1.0f);

		//reset all the things!
		//glLoadIdentity();
	}


	 // ********************

	cout << "Update up" << endl;
}

void Game::draw()
{
	cout << "Draw up" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_QUADS); {
		glVertex3f(-1.0, 1.0, -20.0);
		glVertex3f(-1.0, -1.0, -20.0);
		glVertex3f(1.0, -1.0, -30.0);
		glVertex3f(1.0, 1.0, -30.0); }
	glEnd();

	glBegin(GL_POINTS); {
		glVertex3f(-2.0, 1.0, -20.0);
		glVertex3f(-2.0, -1.0, -20.0); }
	glEnd();

	glBegin(GL_LINES); {
		glVertex3f(-3.0, 1.0, -20.0);
		glVertex3f(-3.0, -1.0, -20.0);
		glVertex3f(-4.0, -2.0, -20.0);
		glVertex3f(-4.0, 2.0, -20.0); }
	glEnd();

	glBegin(GL_LINE_STRIP); {
		glVertex3f(3.0, 1.0, -20.0);
		glVertex3f(3.0, -1.0, -20.0);
		glVertex3f(4.0, -2.0, -20.0);
		glVertex3f(4.0, 2.0, -20.0); }
	glEnd();

	glBegin(GL_LINE_LOOP); {
		glVertex3f(5.0, 1.0, -20.0);
		glVertex3f(5.0, -1.0, -20.0);
		glVertex3f(6.0, -2.0, -20.0);
		glVertex3f(6.0, 2.0, -20.0); }
	glEnd();

	glBegin(GL_TRIANGLES); {
		glVertex3f(-1.0, 3.0, -20.0);
		glVertex3f(-1.0, 2.0, -20.0);
		glVertex3f(1.0, 2.0, -30.0); }
	glEnd();

	glBegin(GL_TRIANGLE_STRIP); {
		glVertex3f(-1.0, 5.0, -20.0);
		glVertex3f(-1.0, 4.0, -20.0);
		glVertex3f(1.0, 4.0, -30.0); }
	glEnd();

	glBegin(GL_TRIANGLE_FAN); {
		glVertex3f(-1.0, -3.0, -20.0);
		glVertex3f(-1.0, -2.0, -20.0);
		glVertex3f(1.0, -2.0, -30.0); }
	glEnd();

	glBegin(GL_QUAD_STRIP); {
		glVertex3f(-1.0, -5.0, -20.0);
		glVertex3f(-1.0, -4.0, -20.0);
		glVertex3f(1.0, -5.0, -30.0);
		glVertex3f(1.0, -4.0, -30.0); }
	glEnd();



	glBegin(GL_POLYGON); {
		glVertex3f(3.0, 5.0, -20.0);
		glVertex3f(2.0, 5.0, -20.0);
		glVertex3f(2.0, 4.0, -30.0);
		glVertex3f(3.0, 3.5, -30.0);
		glVertex3f(4.0, 4.0, -30.0); }
	glEnd();


	 // Uncomment for Part 2
	 // ********************
	//cout << "Draw up" << endl;

	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	////Investigate Here!!!!!

	//cout << "Drawing Primative " << current << endl;
	//glCallList(current);
	 // Uncomment for Part 2
	 // ********************

	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

