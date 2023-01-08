/*** Ejemplo para sensor UVM30A en placa Nodemecu Lolin V3
 *  podemos utilizar el pint A0 de NODEMECU como pin analogo
 *  debemos de fijar los valores de inicio en 0 de manera manual
 * ##el sensor UVM30A nos entrega una lectura en nm(nanometro), esta medida se utiliza para medir la longitud
 * en la radiacion UltraVioleta, infraroja y luz
 * 1nm = 10 a la menos 9 m.
 * ################################
 * la gama espectral del sensor es de 200nm hasta 370nm*
 * voltaje de funcionamiento: 3-5Vdc
 * Corriente: 0.06mA(standard) / 0.1mA(MAXIMO)
 * respuesta de longitud de onda: 200-370nm
 * Temperatura de trabajo: -20º /85ºC
 * ####Hecho por Matias Figueroa 
 * #### Enero 07 2023
 */

#define analogPin A0 // ESP8266 ADC0 = A0
int sensorValue = 0;
int voltaje = 0;

void setup(){
Serial.begin(115200);
delay(2000);
}
void loop (){

sensorValue = analogRead(analogPin);
voltaje = (sensorValue*(3.3/1023.0)*1000);// (sensorValue*(5.0/1023.0)*1000); 5.0 puede varias, esto es de acuerdo al Voltaje de alimentacion de el pin en la placa, en nodemecu es 3.3v en arduino es 5.0v


//comenzamos con la comparacion en rango para  clasificarla en indice de radiacion
if(voltaje<=50){
String IUV0 = "UV 0";
String mes0 = IUV0 + " " + String("Proteccion Minima, use gafas de sol");
//recomendaciones
Serial.print(mes0);
Serial.print("\n");
//envio de datos al server


}else if (voltaje>50 && voltaje<=227){
String IUV1 = " UV 1";
//recomendaciones
String mes1 = IUV1 + " " + String("Proteccion Minima, use gafas de sol");
Serial.print(mes1);
Serial.print("\n");
//envio de datos al server

}else if (voltaje> 227 && voltaje<=318){
String IUV2 = "UV 2";
//recomendaciones
String mes2 = IUV2 + " " + String("Proteccion Minima, use gafas de sol");
Serial.print(mes2);
Serial.print("\n");
//envio de datos al server

} else if (voltaje>318 && voltaje<=408){
String IUV3 ="UV 3";
//recomendaciones
String mes3 = IUV3 + " " + String("Proteccion Moderada, use gafas de sol, Filtro solar,Sombrero,Busque sombras");
Serial.print(mes3);
Serial.print("\n");
//envio de paquete a server

}else if(voltaje>408 && voltaje<=503){
String IUV4="UV 4";
String mes4 = IUV4 + " " + String("Proteccion Moderada, use gafas de sol, Filtro solar,Sombrero,Busque sombras");
Serial.print(mes4);
Serial.print("\n");
//recomendaciones

//envio de paquete a server

}else if(voltaje>503 && voltaje<=606){
String IUV5="UV 5";
String mes5 = IUV5 + " " + String("Proteccion Moderada, use gafas de sol, Filtro solar,Sombrero,Busque sombras");
Serial.print(mes5);
Serial.print("\n");
//recomendaciones

//envio de paquete a server

}else if (voltaje>606 && voltaje<=696){
String IUV6="UV 6";
String mes6 = IUV6 + " " + String("Proteccion Alta!, use gafas de sol, Filtro solar,Sombrero,Busque sombras, no exponga a niños o bebes!,Hidratece!");
Serial.print(mes6);
Serial.print("\n");
//recomendaciones

//envio de datos al server
}else if(voltaje>696 && voltaje<=795){
String IUV7="UV 7";
String mes7 = IUV7 + " " + String("Proteccion Alta!, use gafas de sol, Filtro solar,Sombrero,Busque sombras, no exponga a niños o bebes!,Hidratece!");
Serial.print(mes7);
Serial.print("\n");
//recomendaciones

//envio de datos al server

}else if(voltaje>795 && voltaje<=881){
String IUV8="UV 8";
String mes8 = IUV8 + " " + String("Proteccion Alta!, USE gafas de sol, Filtro solar,Sombrero,No Exponerse al sol!, no exponga a niños o bebes!,Hidratece! ,Evite el sol de 11:00 a 18:00");
Serial.print(mes8);
Serial.print("\n");
//recomendaciones

//envio de datos al server

}else if(voltaje>881 && voltaje<=976){
String IUV9="UV 9";
String mes9 = IUV9 + " " + String("Proteccion Alta!, USE gafas de sol, Filtro solar,Sombrero,No Exponerse al sol!, no exponga a niños o bebes!,Hidratece! ,Evite el sol de 11:00 a 18:00");
Serial.print(mes9);
Serial.print("\n");
//recomendaciones

//envio de datos a server

}else if(voltaje>976 && voltaje<=1079){
String IUV10="UV 10";
String mes10 = IUV10 + " " + String("Proteccion Alta!, USE gafas de sol, Filtro solar,Sombrero,No Exponerse al sol!, no exponga a niños o bebes!,Hidratece! , Evite el sol de 11:00 a 18:00");
Serial.print(mes10);
Serial.print("\n");
 //recomendaciones

//envio de datos al server
}else if(voltaje>1079){
String IUV11="UV 11";
String mes11 = IUV11 + " " + String("NO SALGA DE CASA!");
Serial.print(mes11);
Serial.print("\n");
}
delay(1000);
}
