void aggiornaValori() {

  float voltaggioR = analogRead(A0) * 3.3 / 1024;
  corrente = voltaggioR / 30;
  voltaggio = 5;


  potenza = 5 * corrente;
  potenza = potenza * 1000;
  if (potenza > soglia_potenza)inSovraccarico = true;
  else {
    inSovraccarico = false;
    prima_volta = true;
  }
  if (digitalRead(pannello))inVerde = true;
  else inVerde = false;
}

void statoTraliccio(int mod) {
  switch (mod) {
    case 0:
      digitalWrite(V1, LOW);
      digitalWrite(V2, LOW);
      digitalWrite(G1, LOW);
      digitalWrite(G2, LOW);
      digitalWrite(R1, LOW);
      break;
    case 1:
      digitalWrite(V1, HIGH);
      digitalWrite(V2, LOW);
      digitalWrite(G1, LOW);
      digitalWrite(G2, LOW);
      digitalWrite(R1, LOW);
      break;
    case 2:
      digitalWrite(V1, HIGH);
      digitalWrite(V2, HIGH);
      digitalWrite(G1, LOW);
      digitalWrite(G2, LOW);
      digitalWrite(R1, LOW);
      break;
    case 3:
      digitalWrite(V1, HIGH);
      digitalWrite(V2, HIGH);
      digitalWrite(G1, HIGH);
      digitalWrite(G2, LOW);
      digitalWrite(R1, LOW);
      break;
    case 4:
      digitalWrite(V1, HIGH);
      digitalWrite(V2, HIGH);
      digitalWrite(G1, HIGH);
      digitalWrite(G2, HIGH);
      digitalWrite(R1, LOW);
      break;
    case 5:
      digitalWrite(V1, HIGH);
      digitalWrite(V2, HIGH);
      digitalWrite(G1, HIGH);
      digitalWrite(G2, HIGH);
      digitalWrite(R1, HIGH);
      break;
    case 6:
      digitalWrite(V1, LOW);
      digitalWrite(V2, LOW);
      digitalWrite(G1, LOW);
      digitalWrite(G2, LOW);
      digitalWrite(R1, HIGH);
      break;
    case 7:
      digitalWrite(V1, LOW);
      digitalWrite(V2, LOW);
      digitalWrite(G1, LOW);
      digitalWrite(G2, HIGH);
      digitalWrite(R1, HIGH );
      break;
    case 8:
      digitalWrite(V1, LOW);
      digitalWrite(V2, LOW);
      digitalWrite(G1, HIGH);
      digitalWrite(G2, HIGH);
      digitalWrite(R1, HIGH);
      break;
    case 9:
      digitalWrite(V1, LOW);
      digitalWrite(V2, HIGH);
      digitalWrite(G1, HIGH);
      digitalWrite(G2, HIGH);
      digitalWrite(R1, HIGH);
      break;

  }
}
