package 二分搜索;

import java.util.Scanner;
public class EF {
  public static void main(String[] args) {
      try {
          Scanner scan = new Scanner(System.in);
          System.out.println("请输入元素的个数：");
          int n=scan.nextInt();
          System.out.println("按顺序输入元素：");
          int list[]=new int[n];
          for (int i = 0; i <=list.length-1; i++) {
              String x = scan.next();
              int m=Integer.parseInt(x);
              list[i] = m;
          }
          System.out.println("输入要查找的元素：");
          int key=scan.nextInt();
          System.out.println(key+"的数组下标:"+binarySearch(list, 0, list.length-1, key));
      } catch (Exception e) {
          e.printStackTrace();
      }
  }

  public static int binarySearch(int[] value,int begin,int end, int key) {

      while (begin <= end) {
          int mid = (begin + end) / 2;
          if (value[mid] == key) {

              return mid;
          }
          if (value[mid] > key) {
              return EF.binarySearch(value,begin,mid-1, key);

          } else {

              return EF.binarySearch(value,mid+1,end, key);
          }
      }
      return -1;
  }
}
