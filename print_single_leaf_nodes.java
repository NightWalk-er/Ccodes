public static void printSingleChildNodes(Node node, Node parent){
    if (node == null){
        return;
    }
    
    if (parent != null && parent.left == node && parent.right == null){
        System.out.println(parent.data);
    } else if (parent != null && parent.right == node && parent.left == null){
        System.out.println(parent.data);
    }
    
    printSingleChildNodes(node.left, node);
    printSingleChildNodes(node.right, node);
  }