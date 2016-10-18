#include <Serial.h>
#include <Quadcopter.h>
#include <linAlg.h>
#include <State.h>


geometry geo;
double J_diag[3] = {0.082, 0.0845, 0.1377};



State X0;
Quadcopter quad(geo, X0);
State Xdot;
desDyn Xd;
input u;
double t, t_old;

void setup()
{
  linAlg alg;
  geo.mass = 4.34;
  alg.diag(J_diag, geo.inertia);
  for (int i = 0; i < 3; i++) {
    X0.x[i] = 0;
    X0.v[i] = 0;
    X0.omega[i] = 0;
    X0.e_i[i] = 0;
    X0.e_I[i] = 0;
    for (int j = 0; j < 3; j++) {
      X0.R[i][j] = 0;
      if (i == j) {
        X0.R[i][j] = 1;
      }
    }
  }
  quad.K.Kx = 16;
  quad.K.Kv = 5.6;
  quad.K.KR = 8.81;
  quad.K.KW = 2.5;
  quad.K.Ki = 1;
  quad.K.c1 = 1;
  quad.K.c2 = 1;
  
  Serial.begin(9600);
}

void loop()
{
  t = millis()/1000;
  double dt = t - t_old;
  Xd = quad.ellipticalHelixTrajectory(t);
//  Serial.println(Xd.xd[0]);
  Serial.println(t);
  Serial.println("starting control");
  u = quad.control(t,Xd);
  Serial.println("Finishing control");
//  Xdot = quad.eom(t, u);
//  quad.X.integrateState(dt, Xdot);
//  
//  char stateOut[80];
//  quad.X.printState(stateOut);

//  Serial.println(u.f);
  
  
  t_old = t;
  
}

