/*
 * File: main.c
 * Creator: George Ferguson
 * Created: Mon Nov 28 14:11:17 2016
 * Time-stamp: <Tue Jul 17 16:02:29 EDT 2018 ferguson>
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Circuit.h"

/**
 * Two AND gates connected to make a 3-input AND circuit.
// */
//static Circuit* and3_Circuit() {
//	Boolean* x = new_Boolean(false);
//	Boolean* y = new_Boolean(false);
//	Boolean* z = new_Boolean(false);
//	Boolean** inputs = new_Boolean_array(3);
//	inputs[0] = x;
//	inputs[1] = y;
//	inputs[2] = z;
//
//	Boolean* out = new_Boolean(false);
//	Boolean** outputs = new_Boolean_array(1);
//	outputs[0] = out;
//
//	Gate* A1 = new_AndGate();
//	Gate* A2 = new_AndGate();
//	Gate** gates = new_Gate_array(2);
//	gates[0] = A1;
//	gates[1] = A2;
//
//	Circuit *circuit = new_Circuit(3, inputs, 1, outputs, 2, gates);
//	Circuit_connect(circuit, x, Gate_getInput(A1, 0));
//	Circuit_connect(circuit, y, Gate_getInput(A1, 1));
//	Circuit_connect(circuit, Gate_getOutput(A1), Gate_getInput(A2, 0));
//	Circuit_connect(circuit, z, Gate_getInput(A2, 1));
//	Circuit_connect(circuit, Gate_getOutput(A2), out);
//	return circuit;
//}

static Circuit* circuit_A () {
	Boolean* x = new_Boolean(false);
	Boolean* y = new_Boolean(false);
	Boolean** inputs = new_Boolean_array(2);
	inputs[0] = x;
	inputs[1] = y;

	Boolean* out = new_Boolean(false);
	Boolean** outputs = new_Boolean_array(1);
	outputs[0] = out;

	Gate* N1 = new_Inverter();
	Gate* N2 = new_Inverter();
	Gate* A1 = new_AndGate();
	Gate* A2 = new_AndGate();
	Gate* O1 = new_OrGate();

	Gate** gates = new_Gate_array(5);
	gates[0] = N1;
	gates[1] = N2;
	gates[2] = A1;
	gates[3] = A2;
	gates[4] = O1;

	Circuit *circuit = new_Circuit(2, inputs, 1, outputs, 5, gates);

	Circuit_connect(circuit, x, Gate_getInput(N1, 0));
	Circuit_connect(circuit, y, Gate_getInput(N2, 0));
	Circuit_connect(circuit, x, Gate_getInput(A1, 0));
	Circuit_connect(circuit, Gate_getOutput(N2), Gate_getInput(A1, 1));
	Circuit_connect(circuit, y, Gate_getInput(A2, 1));
	Circuit_connect(circuit, Gate_getOutput(N1), Gate_getInput(A2, 0));
	Circuit_connect(circuit, Gate_getOutput(A1), Gate_getInput(O1, 0));
	Circuit_connect(circuit, Gate_getOutput(A2), Gate_getInput(O1, 1));
	Circuit_connect(circuit, Gate_getOutput(O1), out);
	return circuit;
}

static Circuit* circuit_B () {
	Boolean* x = new_Boolean(false);
	Boolean* y = new_Boolean(false);
	Boolean** inputs = new_Boolean_array(2);
	inputs[0] = x;
	inputs[1] = y;

	Boolean* out = new_Boolean(false);
	Boolean** outputs = new_Boolean_array(1);
	outputs[0] = out;

	Gate* A1 = new_AndGate();
	Gate* A2 = new_AndGate();
	Gate* N1 = new_Inverter();
	Gate* N2 = new_Inverter();
	Gate* A3 = new_AndGate();
	Gate* N3 = new_Inverter();

	Gate** gates = new_Gate_array(6);
	gates[0] = A1;
	gates[1] = A2;
	gates[2] = N1;
	gates[3] = N2;
	gates[4] = A3;
	gates[5] = N3;

	Circuit *circuit = new_Circuit(2, inputs, 1, outputs, 6, gates);
	Circuit_connect(circuit, x, Gate_getInput(A1, 0));
	Circuit_connect(circuit, y, Gate_getInput(A1, 1));
	Circuit_connect(circuit, x, Gate_getInput(A2, 0));
	Circuit_connect(circuit, y, Gate_getInput(A2, 1));
	Circuit_connect(circuit, Gate_getOutput(A1), Gate_getInput(N1, 0));
	Circuit_connect(circuit, Gate_getOutput(A2), Gate_getInput(N2, 0));
	Circuit_connect(circuit, Gate_getOutput(N1), Gate_getInput(A3, 0));
	Circuit_connect(circuit, Gate_getOutput(N2), Gate_getInput(A3, 1));
	Circuit_connect(circuit, Gate_getOutput(A3), Gate_getInput(N3, 0));
	Circuit_connect(circuit, Gate_getOutput(N3), out);
	return circuit;
}

static Circuit* circuit_C () {
	Boolean* x = new_Boolean(false);
	Boolean* y = new_Boolean(false);
	Boolean* z = new_Boolean(false);
	Boolean** inputs = new_Boolean_array(3);
	inputs[0] = x;
	inputs[1] = y;
	inputs[2] = z;

	Boolean* out = new_Boolean(false);
	Boolean** outputs = new_Boolean_array(1);
	outputs[0] = out;

	Gate* A1 = new_AndGate();
	Gate* A2 = new_AndGate();
	Gate* A3 = new_AndGate();
	Gate* O1 = new_OrGate();
	Gate* O2 = new_OrGate();

	Gate** gates = new_Gate_array(5);
	gates[0] = A1;
	gates[1] = A2;
	gates[2] = A3;
	gates[3] = O1;
	gates[4] = O2;

	Circuit *circuit = new_Circuit(3, inputs, 1, outputs, 5, gates);
	Circuit_connect(circuit, x, Gate_getInput(A1, 0));
	Circuit_connect(circuit, y, Gate_getInput(A1, 1));
	Circuit_connect(circuit, x, Gate_getInput(A2, 0));
	Circuit_connect(circuit, z, Gate_getInput(A2, 1));
	Circuit_connect(circuit, y, Gate_getInput(A3, 0));
	Circuit_connect(circuit, z, Gate_getInput(A3, 1));
	Circuit_connect(circuit, Gate_getOutput(A1), Gate_getInput(O1, 0));
	Circuit_connect(circuit, Gate_getOutput(A2), Gate_getInput(O1, 1));
	Circuit_connect(circuit, Gate_getOutput(O1), Gate_getInput(O2, 0));
	Circuit_connect(circuit, Gate_getOutput(A3), Gate_getInput(O2, 1));
	Circuit_connect(circuit, Gate_getOutput(O2), out);
	return circuit;

}

static Circuit* circuit_F () {
	Boolean* a = new_Boolean(false);
	Boolean* b = new_Boolean(false);
	Boolean* c = new_Boolean(false);
	Boolean** inputs = new_Boolean_array(3);
	inputs[0] = a;
	inputs[1] = b;
	inputs[2] = c;

	Boolean* out = new_Boolean(false);
	Boolean** outputs = new_Boolean_array(1);
	outputs[0] = out;

	Gate** gates = new_Gate_array(13);
	Gate* N1 = new_Inverter();
	Gate* N2 = new_Inverter();
	Gate* N3 = new_Inverter();
	Gate* A1 = new_AndGate();
	Gate* A2 = new_AndGate();
	Gate* A3 = new_AndGate();
	Gate* A4 = new_AndGate();
	Gate* A5 = new_AndGate();
	Gate* A6 = new_AndGate();
	Gate* A7 = new_AndGate();
	Gate* O1 = new_OrGate();
	Gate* O2 = new_OrGate();
	Gate* O3 = new_OrGate();

	gates[0] = N1;
	gates[1] = N2;
	gates[2] = N3;
	gates[3] = A1;
	gates[4] = A2;
	gates[5] = A3;
	gates[6] = A4;
	gates[7] = A5;
	gates[8] = A6;
	gates[9] = A7;
	gates[10] = O1;
	gates[11] = O2;
	gates[12] = O3;


	Circuit *circuit = new_Circuit(3, inputs, 1, outputs, 13, gates);
	Circuit_connect(circuit, a, Gate_getInput(N1, 0));
	Circuit_connect(circuit, b, Gate_getInput(N2, 0));
	Circuit_connect(circuit, c, Gate_getInput(N3, 0));
	Circuit_connect(circuit, Gate_getOutput(N1), Gate_getInput(A1, 0));
	Circuit_connect(circuit, Gate_getOutput(N2), Gate_getInput(A1, 1));
	Circuit_connect(circuit, Gate_getOutput(A1), Gate_getInput(A2, 0));
	Circuit_connect(circuit, Gate_getOutput(N3), Gate_getInput(A2, 1));
	Circuit_connect(circuit, Gate_getOutput(A1), Gate_getInput(A3, 0));
	Circuit_connect(circuit, c, Gate_getInput(A3, 1));
	Circuit_connect(circuit, Gate_getOutput(N1), Gate_getInput(A4, 0));
	Circuit_connect(circuit, b, Gate_getInput(A4, 1));
	Circuit_connect(circuit, Gate_getOutput(A4), Gate_getInput(A5, 0));
	Circuit_connect(circuit, Gate_getOutput(N3), Gate_getInput(A5, 1));
	Circuit_connect(circuit, Gate_getOutput(N2), Gate_getInput(A6, 0));
	Circuit_connect(circuit, Gate_getOutput(N3), Gate_getInput(A6, 1));
	Circuit_connect(circuit, a, Gate_getInput(A7, 0));
	Circuit_connect(circuit, Gate_getOutput(A6), Gate_getInput(A7, 1));
	Circuit_connect(circuit, Gate_getOutput(A3), Gate_getInput(O1, 0));
	Circuit_connect(circuit, Gate_getOutput(A2), Gate_getInput(O1, 1));
	Circuit_connect(circuit, Gate_getOutput(A7), Gate_getInput(O2, 0));
	Circuit_connect(circuit, Gate_getOutput(A5), Gate_getInput(O2, 1));
	Circuit_connect(circuit, Gate_getOutput(O2), Gate_getInput(O3, 0));
	Circuit_connect(circuit, Gate_getOutput(O1), Gate_getInput(O3, 1));
	Circuit_connect(circuit, Gate_getOutput(O3), out);

	return circuit;
}

static Circuit* circuit_G () {
	Boolean* a = new_Boolean(false);
	Boolean* b = new_Boolean(false);
	Boolean* c = new_Boolean(false);
	Boolean** inputs = new_Boolean_array(3);
	inputs[0] = a;
	inputs[1] = b;
	inputs[2] = c;

	Boolean* out = new_Boolean(false);
	Boolean** outputs = new_Boolean_array(1);
	outputs[0] = out;

	Gate* N1 = new_Inverter();
	Gate* N2 = new_Inverter();
	Gate* N3 = new_Inverter();
	Gate* A1 = new_AndGate();
	Gate* A2 = new_AndGate();
	Gate* A3 = new_AndGate();
	Gate* A4 = new_AndGate();
	Gate* A5 = new_AndGate();
	Gate* A6 = new_AndGate();
	Gate* A7 = new_AndGate();
	Gate* A8 = new_AndGate();
	Gate* O1 = new_OrGate();
	Gate* O2 = new_OrGate();
	Gate* O3 = new_OrGate();

	Gate** gates = new_Gate_array(14);
	gates[0] = N1;
	gates[1] = N2;
	gates[2] = N3;
	gates[3] = A1;
	gates[4] = A2;
	gates[5] = A3;
	gates[6] = A4;
	gates[7] = A5;
	gates[8] = A6;
	gates[9] = A7;
	gates[10] = A8;
	gates[11] = O1;
	gates[12] = O2;
	gates[13] = O3;

	Circuit *circuit = new_Circuit(3, inputs, 1, outputs, 14, gates);
	Circuit_connect(circuit, a, Gate_getInput(N1, 0));
	Circuit_connect(circuit, b, Gate_getInput(N2, 0));
	Circuit_connect(circuit, c, Gate_getInput(N3, 0));

	Circuit_connect(circuit, Gate_getOutput(N1), Gate_getInput(A1, 0));
	Circuit_connect(circuit, Gate_getOutput(N2), Gate_getInput(A1, 1));
	Circuit_connect(circuit, Gate_getOutput(A1), Gate_getInput(A2, 0));
	Circuit_connect(circuit, Gate_getOutput(N3), Gate_getInput(A2, 1));
	Circuit_connect(circuit, Gate_getOutput(N1), Gate_getInput(A3, 0));
	Circuit_connect(circuit, b, Gate_getInput(A3, 1));
	Circuit_connect(circuit, Gate_getOutput(A3), Gate_getInput(A4, 0));
	Circuit_connect(circuit, c, Gate_getInput(A4, 1));
	Circuit_connect(circuit, a, Gate_getInput(A5, 0));
	Circuit_connect(circuit, Gate_getOutput(N2), Gate_getInput(A5, 1));
	Circuit_connect(circuit, Gate_getOutput(A5), Gate_getInput(A6, 0));
	Circuit_connect(circuit, c, Gate_getInput(A6, 1));
	Circuit_connect(circuit, b, Gate_getInput(A7, 0));
	Circuit_connect(circuit, Gate_getOutput(N3), Gate_getInput(A7, 1));
	Circuit_connect(circuit, a, Gate_getInput(A8, 0));
	Circuit_connect(circuit, Gate_getOutput(A7), Gate_getInput(A8, 1));
	Circuit_connect(circuit, Gate_getOutput(A2), Gate_getInput(O1, 0));
	Circuit_connect(circuit, Gate_getOutput(A4), Gate_getInput(O1, 1));
	Circuit_connect(circuit, Gate_getOutput(A6), Gate_getInput(O2, 0));
	Circuit_connect(circuit, Gate_getOutput(A8), Gate_getInput(O2, 1));
	Circuit_connect(circuit, Gate_getOutput(O2), Gate_getInput(O3, 0));
	Circuit_connect(circuit, Gate_getOutput(O1), Gate_getInput(O3, 1));
	Circuit_connect(circuit, Gate_getOutput(O3), out);

	return circuit;

}

static char* b2s(bool b) {
	return b ? "T" : "F";
}

//static void test3In1Out(Circuit* circuit, bool in0, bool in1, bool in2) {
//	Circuit_setInput(circuit, 0, in0);
//	Circuit_setInput(circuit, 1, in1);
//	Circuit_setInput(circuit, 2, in2);
//	Circuit_update(circuit);
//	bool out0 = Circuit_getOutput(circuit, 0);
//	printf("%s %s %s -> %s\n", b2s(in0), b2s(in1), b2s(in2), b2s(out0));
//}

static void printTruthTable (Circuit* circuit){
	bool x = false;
	bool y = false;
	bool z = false;

	int numIn = Circuit_numInputs(circuit);
	int numCol = pow(2, numIn);
	for (int i = 1; i <= numCol; i++){
		if (i== (numCol/2 + 1)){
			x = !x;
			y = !y;
			z = !z;
		} else if (i%2 == 0){
			z = !z;
		} else if (i % 2 != 0  && i > 1){
			y = !y;
			z = !z;
		} else{

		}
		if (numIn == 2){
			printf("%d %d\n", y, z);
			Circuit_setInput(circuit, 0, y);
			Circuit_setInput(circuit, 1, z);
			Circuit_update(circuit);
			bool out0 = Circuit_getOutput(circuit, 0);
			printf("%s %s -> %s\n", b2s(y), b2s(z), b2s(out0));
			Circuit_dump(circuit);
		} else{
			printf("%d %d %d\n", x, y, z);
			Circuit_setInput(circuit, 0, x);
			Circuit_setInput(circuit, 1, y);
			Circuit_setInput(circuit, 2, z);
			Circuit_update(circuit);
			bool out0 = Circuit_getOutput(circuit, 0);
			printf("%s %s %s -> %s\n", b2s(x), b2s(y), b2s(z), b2s(out0));
			Circuit_dump(circuit);
		}
	}
}



int main(int argc, char **argv) {
	printf("Welcome to Nadine and Claudia's Project 5!\n");

	printf("Press RETURN to continue.");
	getchar();

	printf("\n\nTesting circuit a:\n");
	Circuit* circuitA = circuit_A();
	printTruthTable(circuitA);
	Circuit_free(circuitA);

	printf("Press RETURN to continue.");
	getchar();

	printf("\n\nTesting circuit b:\n");
	Circuit* circuitB = circuit_B();
	printTruthTable(circuitB);
	Circuit_free(circuitB);

	printf("Press RETURN to continue.");
	getchar();

	printf("\n\nTesting circuit c:\n");
	Circuit* circuitC = circuit_C();
	printTruthTable(circuitC);
	Circuit_free(circuitC);

	printf("Press RETURN to continue.");
	getchar();

	printf("\n\nTesting extra credit circuit f:\n");
	Circuit* circuitF = circuit_F();
	printTruthTable(circuitF);
	Circuit_free(circuitF);

	printf("Press RETURN to continue.");
	getchar();

	printf("\n\nTesting extra credit circuit g:\n");
	Circuit* circuitG = circuit_G();
	printTruthTable(circuitG);
	Circuit_free(circuitG);
	printf("Done! :)");
}
