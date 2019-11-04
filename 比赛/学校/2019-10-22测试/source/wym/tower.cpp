#include<bits/stdc++.h>
int min_signaltower_cost,edge_count,num_signaltower,earlist_ancest[1010],match_count,temp_variable1,temp_variable2;
inline int quick_read(){
    int result=0,result_sign=1;
    char temp_digit=getchar();
    while(temp_digit<'0'||temp_digit>'9')
	{
        if(temp_digit=='-')
            result_sign=-1;
        temp_digit=getchar();
    }
    while(temp_digit>='0'&&temp_digit<='9')
	{
        result=(result<<1)+(result<<3)+(temp_digit^48);
        temp_digit=getchar();
    }
    return result*result_sign;
}
struct type_signaltower{
	int x_coordinate,y_coordinate;
}signaltower[1010];
struct type_edge{
	int start_point,destination,edge_value;
}edge[2000010];
inline void add_edge(int new_edge_from,int new_edge_destination,int new_edge_value){
	edge[++edge_count]=(type_edge){new_edge_from,new_edge_destination,new_edge_value};
}
inline int calculate_distance(type_signaltower signaltower1,type_signaltower signaltower2){
	return (signaltower1.x_coordinate-signaltower2.x_coordinate)*(signaltower1.x_coordinate-signaltower2.x_coordinate)+(signaltower1.y_coordinate-signaltower2.y_coordinate)*(signaltower1.y_coordinate-signaltower2.y_coordinate);
}
bool edge_compare_lesser(type_edge edge1,type_edge edge2){
	return edge1.edge_value<edge2.edge_value;
}
inline int find_ancest(int target){
	if(earlist_ancest[target]==target)
		return target;
	return earlist_ancest[target]=find_ancest(earlist_ancest[target]);
}
int main(){
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	std::ios::sync_with_stdio(false);
	num_signaltower=quick_read();
	for(int temp_signaltower=1;temp_signaltower<=num_signaltower;++temp_signaltower){
		earlist_ancest[temp_signaltower]=temp_signaltower;
	}
	for(int temp_signaltower=1;temp_signaltower<=num_signaltower;++temp_signaltower){
		signaltower[temp_signaltower]=(type_signaltower){quick_read(),quick_read()};
	}
	for(int temp_from=1;temp_from<=num_signaltower;++temp_from){
		for(int temp_destination=temp_from+1;temp_destination<=num_signaltower;++temp_destination){
			add_edge(temp_from,temp_destination,calculate_distance(signaltower[temp_from],signaltower[temp_destination]));
		}
	}
	std::sort(edge+1,edge+edge_count+1,edge_compare_lesser);
	int temp_edge_from_ancest,temp_edge_destination_ancest;
	for(int temp_edge=1;match_count<num_signaltower-1;++temp_edge){
		temp_edge_from_ancest=find_ancest(edge[temp_edge].start_point);
		temp_edge_destination_ancest=find_ancest(edge[temp_edge].destination);
		if(temp_edge_destination_ancest!=temp_edge_from_ancest){
			earlist_ancest[temp_edge_from_ancest]=earlist_ancest[temp_edge_destination_ancest];
			min_signaltower_cost=edge[temp_edge].edge_value;
			match_count++;
		}
	}
	std::cout<<min_signaltower_cost;
	return 0;
}
/*�����ֵ����ϲ���Ķ��Ŵ����£����˽⵽�Ŵ�ս����ͨ�����̨������Ϣ�ģ���Ҳ��
ģ��һ��������̡�
������ n �����̨��ÿ�����̨����һ���ľ��ѣ���þ��Ѷ�Ŀ��Բɹ������ȼ��
���������̣��������ǵ���Ϣ�Ϳ��Դ��ݵĸ�Զ������Ϊ p �ķ��̨���Դ�����Ϣ�ľ�
����� �����̨����Ϣ����ͨ���������̨���н飬�������볬�� �ķ��̨��λ�á�
�����ֵ¾�����ÿ�����̨���Ѷ�Ϊ x�������æȷ��һ�� x ����Сֵ��ʹ����һ���
̨��������Ϣ���ܵ����������з��̨��
�����ʽ tower.in��
����ĵ�һ��һ������ n����ʾ�� n �����̨��
������ n ��ÿ���������� x, y���ֱ��ʾ�÷��̨������(x, y)��
�����ʽ tower.out��
���һ����������ʾ x ����Сֵ��
�������룺
4
1 3
5 4
7 2
6 1
���������
17
���ݷ�Χ��
1<=n<=1000
1<=x, y<=25000*/
