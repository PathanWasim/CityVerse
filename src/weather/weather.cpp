#include "weather.h"

void updateDayNightCycle() {
	timeOfDay += 0.5f;
	if (timeOfDay > 360.0f) timeOfDay = 0.0f;
	lightIntensity = sin(timeOfDay * M_PI / 180.0f);
	if (lightIntensity < 0.0f) lightIntensity = 0.0f;
	float skyR = 0.0f + 0.5f * (1 + sin(timeOfDay * M_PI / 180.0f));
	float skyG = 0.5f + 0.5f * (1 + sin((timeOfDay + 120) * M_PI / 180.0f));
	float skyB = 0.5f + 0.5f * (1 + sin((timeOfDay + 240) * M_PI / 180.0f));
	glClearColor(skyR, skyG, skyB, 1.0f);
	if (lightIntensity < 0.3f) {
		glEnable(GL_LIGHT0);
	} else {
		glDisable(GL_LIGHT0);
	}
}

void drawWeatherEffects() {
	if (currentWeather == RAINY) {
		glColor4f(0.7f, 0.7f, 1.0f, 0.5f);
		for (int i = 0; i < 100; i++) {
			float x = rand() % 400 - 200;
			float y = rand() % 400 - 200;
			float z = rand() % 400 - 200;
			glBegin(GL_LINES);
			glVertex3f(x, 200, z);
			glVertex3f(x, 0, z);
			glEnd();
		}
	}
}

void drawRain() {
	glColor4f(0.7f, 0.7f, 1.0f, 0.5f);
	for (int i = 0; i < 100; i++) {
		float x = rand() % 400 - 200;
		float y = rand() % 400;
		float z = rand() % 400 - 200;
		glBegin(GL_LINES);
		glVertex3f(x, y, z);
		glVertex3f(x, y - 10, z);
		glEnd();
	}
}

void setupFog() {
	GLfloat fogColor[4] = { 0.7f, 0.7f, 0.7f, 1.0f };
	glFogi(GL_FOG_MODE, GL_LINEAR);
	glFogfv(GL_FOG_COLOR, fogColor);
	glFogf(GL_FOG_DENSITY, 0.1f);
	glHint(GL_FOG_HINT, GL_NICEST);
	glFogf(GL_FOG_START, 100.0f);
	glFogf(GL_FOG_END, 300.0f);
	glEnable(GL_FOG);
}
