package GiocoOca;
/* Itinere */
public class App{
    public static void main(String[] args) throws Exception{
        
    Game g = new Game();

    // players
    Thread a = new Player(0, g);
    Thread b = new Player(1, g);

    a.start();
    b.start();

    a.join();
    b.join(); 
    System.out.println("Game over");
    }

}