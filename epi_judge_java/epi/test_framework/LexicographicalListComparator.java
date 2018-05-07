
package epi.test_framework;

import java.util.Comparator;
import java.util.Iterator;
import java.util.List;

public class LexicographicalListComparator<T extends Comparable<T>>
    implements Comparator<List<T>> {
  @Override
  public int compare(List<T> o1, List<T> o2) {
    Iterator<T> i1 = o1.iterator();
    Iterator<T> i2 = o2.iterator();
    int result;

    do {
      if (!i1.hasNext()) {
        if (!i2.hasNext())
          return 0;
        else
          return -1;
      }
      if (!i2.hasNext()) {
        return 1;
      }

      result = i1.next().compareTo(i2.next());
    } while (result == 0);

    return result;
  }
}
