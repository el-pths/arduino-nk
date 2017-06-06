#define A 8
#define B 7
#define C 4
#define D 3
#define E 2
#define F 6
#define G 5

#define CH 9

int nums[][7] = {
	{0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 1, 1, 1},
	{0, 0, 1, 0, 0, 1, 0},
	{0, 0, 0, 0, 1, 1, 0},
	{1, 0, 0, 1, 1, 0, 0},
	{0, 1, 0, 0, 1, 0, 0},
	{0, 1, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 1, 1, 1},
	{0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 0, 0},
};

int num1, num2, dsp1, dsp2, result;
bool flag = false;

void setup() {
	pinMode(CH, OUTPUT);
	
	pinMode(A, OUTPUT);
	pinMode(B, OUTPUT);
	pinMode(C, OUTPUT);
	pinMode(D, OUTPUT);
	pinMode(E, OUTPUT);
	pinMode(F, OUTPUT);
	pinMode(G, OUTPUT);
}

void loop() {
	int sensorValue1 = analogRead(A0);
	int sensorValue2 = analogRead(A1);

	if (digitalRead(10) == 1)
	      flag = true;
	if (digitalRead(11) == 1)
	      flag = false;

	if (sensorValue1 > 1000)
	      sensorValue1 = 999;
	if (sensorValue2 > 1000)
	      sensorValue2 = 999;

	num1 = sensorValue1 / 100;
	num2 = sensorValue2 / 100;
	result = num1 * num2;

	if (flag) {
		dsp1 = result / 10;
		dsp2 = result % 10;
		} else {
		dsp1 = num1;
		dsp2 = num2;
	}
	
	digitalWrite(CH, HIGH);
	displayChar(nums[dsp1]);
	delay(1);

	digitalWrite(CH, LOW);
	displayChar(nums[dsp2]);
	delay(1);
}

void displayChar(int ch[]) {
	digitalWrite(A, ch[0]);
	digitalWrite(B, ch[1]);
	digitalWrite(C, ch[2]);
	digitalWrite(D, ch[3]);
	digitalWrite(E, ch[4]);
	digitalWrite(F, ch[5]);
	digitalWrite(G, ch[6]);
}
