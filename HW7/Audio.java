public class Audio extends DatasetObject implements Playable, NonVisual { // to define Audio class.
    private String duration; // to define private string variable for duration.

    public Audio(String name, String duration, String otherInfo) { // to define constructor for Audio object.
        super(name, otherInfo); // to assign parameters to members with using constructor of abstract class.
        this.duration = duration;
    }

    public String getDuration() { // to define getter function for duration.
        return duration;
    }

    public void info() { // to define info function for get info of audio object.
        System.out.println("Audio object: " + getName() + ", " + getDuration() + "," + getOtherInfo());
    }
}
