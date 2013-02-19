package university;

import java.util.ArrayList;

public class SortedList<T extends Comparable<? super T>> {
	//@ invariant (\forall int i; (i >= 0 && i < size()); get(i).compareTo(get(i+1)) <= 0);
	
	private /*@ spec_public @*/ ArrayList<T> list;
	
	//@ ensures size() == 0;
	public SortedList() {
		list = new ArrayList<T>();
	}
	
	//@ ensures \result >= 0;
	public /*@ pure @*/ int size() {
		return list.size();
	}
	
	/*@ requires (index >= 0)
	  @ 	  && (index < size());
	  @*/
	public /*@ pure @*/ T get(int index) {
		return list.get(index);
	}
	
	/*@ ensures (size() == (\old(size()) + 1))
	  @		 && (count(element) == (\old(count(element)) + 1));
	  @ */
	public void add(/*@ non_null @*/ T element) {
		int i = 0;
		while (i < list.size() && list.get(i).compareTo(element) <= 0) 	{ ++i; }
		list.add(i, element);
	}
	
	/*@ ensures (\old(count(element)) > 0) <==>
	  @			(
	  @ 			(\result == true)
	  @			 && (size() == \old(size()) - 1)
	  @			 && (count(element) == \old(count(element)) - 1)
	  @			);
	  @ */
	public boolean remove(/*@ non_null @*/ T element) {
		return list.remove(element);
	}
	
	//@ ensures \result >= 0;
	public /*@ pure @*/ int count(/*@ non_null @*/ T element) {
		int count = 0;
		for (T x : list)
			if (element.equals(x))
				++count;
		return count;
	}
	
	@Override
	public /*@ pure @*/ /*@ non_null @*/ String toString() {
		return "" + list.toString();
	}
	
}
