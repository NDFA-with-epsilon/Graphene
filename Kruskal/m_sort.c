#include "m_sort.h"

int sort_list(adj_list* g_list, int vertex, int l, int r)
{
	if(l >= r)
	{
		return;
	}

	int mid = floor(l + ((r - l)/ 2));

	sort_list(g_list, vertex, l, mid);
	sort_list(g_list, vertex, mid + 1, r);

	merge(g_list, vertex, l, mid, r);
	return SUCCESS;
}

void merge(adj_list* g_list, int vertex, int l, int mid, int r)
{
	int l_half = mid - l + 1;
	int r_half = r - mid;

	list* l_buf = malloc(l_half * sizeof(list));
	list* r_buf = malloc(r_half * sizeof(list));
   
	for(int i = 0; i < l_half; i++)
	{
		l_buf[i] = g_list[vertex - 1].head[l+i];
	}
    
	for(int j = 0; j < r_half; j++)
	{
		r_buf[j] = g_list[vertex - 1].head[mid + 1 + j];
	}

	int lc = 0, rc = 0;
	enum first_buf_to_fill
	{
		none,
		left,
		right
	}lrbuf; 
    lrbuf = none;
    
    for(int i = l; i < r + 1; i++)
	{	
		if(lrbuf == none) //both bufs are non-empty
		{
			if(l_buf[lc].weight < r_buf[rc].weight)
			{
				g_list[vertex - 1].head[i] = l_buf[lc];

				if(lc + 1 < l_half)	//l_buf is still non-empty
				{
					lc += 1; continue;
				}

				else	//l_buf is empty now
				{
					lrbuf = left; continue;
				}
			}

			else
			{
				g_list[vertex - 1].head[i] = r_buf[rc];

				if(rc + 1 < r_half)	//r_buf is still non-empty
				{
					rc += 1; continue;
				}
				else	//r_buf is empty now
				{
					lrbuf = right; continue;
				}
			}
			//condition for equal entries in l_buf & r_buf	
		}

		else if(lrbuf == left)	//l_buf has been emptied, now read from r_buf sequentially
		{
			g_list[vertex - 1].head[i] = r_buf[rc];
			if(rc + 1 == r_half) //r_buf is also empty now, so terminate loop
			{
				break;
			}
			
			else
			{
				rc += 1; continue;
			}
		}

		else	//r_buf is empty, now read from l_buf
		{
			g_list[vertex - 1].head[i] = l_buf[lc];
			if(lc + 1 == l_half)	//l_buf is also empty now, so terminate loop
			{
				break;
			}

			else
			{
				lc += 1; continue;
			}
		}
	}

    free(l_buf);
    free(r_buf);
}