public class StringCompressor {

    public static String compressString(String s) {
        if (s == null || s.isEmpty()) {
            System.out.println("Original: \"\"");
            System.out.println("Compressed: \"\"");
            return s;
        }

        StringBuilder compressed = new StringBuilder();
        int count = 1;

        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == s.charAt(i - 1)) {
                count++;
            } else {
                compressed.append(s.charAt(i - 1)).append(count);
                count = 1;
            }
        }

        compressed.append(s.charAt(s.length() - 1)).append(count);

        String result = compressed.toString();
        System.out.println("Original: " + s);
        System.out.println("Compressed: " + (result.length() < s.length() ? result : s));

        return result.length() < s.length() ? result : s;
    }

    public static void main(String[] args) {
        compressString("aabcccccaaa");
        compressString("abc");
    }
}
