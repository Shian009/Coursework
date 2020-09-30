import java.util.Scanner;

class customException extends Exception
{
	String s=" ";
  public customException(String message)
  {
    super(message);
	s=message;
  }
  public String toString()
  {
	  return s;
  }
}

class LinkedList
{
	class Node
	{
		int data;
		Node next;

		Node(int data)
		{
			this.data = data;
			next=null;
		}
	}

	Node head;

	void insert(int data)
	{
		Node node = new Node(data);

		if(head == null || data <= head.data)
		{
			node.next = head;
			head = node;
		}

		else
		{
			Node temp = head;
			while(temp.next != null)
			{
				if(data <= temp.next.data)
				{
					node.next = temp.next;
					temp.next = node;
					return;
				}
				temp = temp.next;
			}
			temp.next = node;
		}
	}

	int deleteFirst() throws customException
	{
		int x;
		if(head == null)
			throw (new customException("List is Empty"));
		else
			{
				x=head.data;
				head = head.next;
			}
		return x;
	}

	int deleteLast() throws customException
	{
		int x;
		if(head == null)
			throw (new customException("List is Empty"));

		else if(head.next == null)
			{	
				x=head.data;
				head = null;
			}

		else
		{
			Node temp = head;

			while(temp.next.next != null)
				temp = temp.next;
			x=temp.next.data;
			temp.next = null;
		}
		return x;
	}

	int deleteIndex(int index) throws customException
	{
		Node temp = head;
		if(temp==null)
		{
			throw (new customException("List is Empty"));
		}
		if(index == 0)
		{
			return deleteFirst();
		}
		int i = 0;
		if(temp.next==null)
		{
			throw (new customException("Invalid Index"));		//for single node
		}
		while(i != index - 1)
		{
			temp = temp.next;
			if(temp.next == null)
			{
				throw (new customException("Invalid Index"));
			}
			i++;
		}
		i=temp.next.data;
		temp.next = temp.next.next;
		return i;
	}

	void merge(Node n1, Node n2)
	{
		Node temp = head;
		Node node;
		while(n1 != null && n2 != null)
		{
			if(n1.data < n2.data)
			{
				in(n1.data);
				n1 = n1.next;
			}

			else if(n2.data < n1.data)
			{
				in(n2.data);
				n2 = n2.next;
			}

			else
			{
				
				in(n1.data);
				in(n2.data);
				n1 = n1.next;
				n2 = n2.next;
			}
		}

		while(n1 != null)
		{
			in(n1.data);
			n1 = n1.next;
		}
		while(n2 != null)
		{
			in(n2.data);
			n2 = n2.next;
		}
	}
	void in(int d)
	{
		Node node = new Node(d);

		if(head == null)
		{
			node.next = head;
			head = node;
		}
		else
		{
			Node temp = head;
			Node p=head;
			while(temp != null)
			{
				p=temp;
				temp = temp.next;
			}
			p.next = node;
		}
	}

	void show()
	{
		if(head == null)
		{
			System.out.println("\nList is Empty");
			return;
		}

		Node temp = head;
		while(temp != null)
		{
			System.out.print(temp.data + " ");
			temp = temp.next;
		}
		System.out.println();
	}
}

class P14
{
	public static void main(String[] args)
	{
		Scanner read = new Scanner(System.in);
		int a;
		LinkedList list1 = new LinkedList();
		int option;

		do
		{
			System.out.println("\n1.Insert\n2.DeleteFirst\n3.DeleteLast\n4.DeleteIndex\n5.Merge\n6.Show List1\n0.Exit");
			option = read.nextInt();

			switch(option)
			{
				case 1:
					System.out.print("\nEnter the element: ");
					list1.insert(read.nextInt());
				break;

				case 2:	try{
							a=list1.deleteFirst();
							System.out.println("Deleted Element is: "+a);
						}
						catch(customException e)
						{
							System.out.println(e);
						}	
						break;

				case 3:	try{
							a=list1.deleteLast();
							System.out.println("Deleted Element is: "+a);
						}
						catch(customException e)
						{
							System.out.println(e);
						}	
						break;

				case 4:	try{
							System.out.print("\nEnter the index: ");
							a=list1.deleteIndex(read.nextInt());
							System.out.println("Deleted Element's data is: "+a);
						}
						catch(customException e)
						{
							System.out.println(e);
						}						
						break;

				case 5:
					LinkedList list2 = new LinkedList();
					System.out.print("\nNo. of elements in list2: ");
					int n = read.nextInt();

					System.out.println("Enter the list");
					for(int i = 0; i < n; i++)
						list2.insert(read.nextInt());

					LinkedList mergedList = new LinkedList();
					mergedList.merge(list1.head, list2.head);
					list1=mergedList;
					System.out.println("\nMerged List");
					mergedList.show();
				break;

				case 6:
					list1.show();
				break;
			}
		}
		while(option != 0);
	}
}












