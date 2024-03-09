public class DatasetObject { // to define datasetObject class.
    private String name;
    private String otherInfo;

    public DatasetObject() { // to define default constructor.
    }

    public DatasetObject(String name, String otherInfo) { // to define with parameter constructor.
        this.name = name;
        this.otherInfo = otherInfo;
    }

    public String getName() { // to define getter function for name.
        return name;
    }

    public String getOtherInfo() {// to define getter function for other info.
        return otherInfo;
    }
}