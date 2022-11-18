size (500,500);

background(#B4F7FF);

//stelo
stroke(0,180,0,255);
strokeWeight(3);

line(width/2,height-height/8,width/2,height/3);

int diametro = 80;

//cerchi esterni
/*noStroke();
fill(#AA00AA);
ellipse(width/2+35,height/2+35,150,150);
ellipse(width/2+35,height/2-35,150,150);
ellipse(width/2-35,height/2-35,150,150);
ellipse(width/2-35,height/2+35,150,150);


fill(#D500D5);
ellipse(width/2,height/2+60,100,100);
ellipse(width/2,height/2-60,100,100);
ellipse(width/2-60,height/2,100,90);
ellipse(width/2+60,height/2,100,100);

fill(#FF00FF);
*/

ellipseMode(CENTER);
noStroke();

fill(#FF00FF);
ellipse(width/2-diametro/2,height/3-diametro/3,diametro+diametro/3,diametro+diametro/3);
ellipse(width/2+diametro/2,height/3-diametro/3,diametro+diametro/3,diametro+diametro/3);
ellipse(width/2+diametro/2,height/3+diametro/3,diametro+diametro/3,diametro+diametro/3);
ellipse(width/2-diametro/2,height/3+diametro/3,diametro+diametro/3,diametro+diametro/3);



fill(#FF0000);
ellipse(width/2,height/3,diametro,diametro);
