
import java.io.RandomAccessFile;

class Test {

    public static void main(String[] args) throws Exception {
        RandomAccessFile raf = new RandomAccessFile("test.txt", "rw");
        raf.setLength(100 * 1024);
        raf.close();
    }

}
