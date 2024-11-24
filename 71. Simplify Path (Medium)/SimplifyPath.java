class Solution {
    public String simplifyPath(String path) {
        // quite optimize solution
        Stack<String> stack = new Stack<>();
        // split the path by '/' to process each part
        String[] components = path.split("/");

        for (String component : components) {
            // ".." = go up one directory if possible
            if (component.equals("..")) {
                if (!stack.isEmpty()) {
                    stack.pop(); // go back to the previous directory
                }
            // valid directory
            } else if (!component.equals(".") && !component.isEmpty()) {
                stack.push(component);
            }
            // ignore "." and '//'
        }

        // build the simplified path
        String result = "";
        for (String dir : stack) {
            result += "/" + dir;
        }

        return result.length() > 0 ? result.toString() : "/";
    }
}
