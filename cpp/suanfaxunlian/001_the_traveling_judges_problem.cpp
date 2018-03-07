//
// Created by aria on 18-3-4.
//

/*问题描述
　　一组人要担任在一个特定城市举办的比赛的评委，他们需要找到最便宜的租车方式使得每个人都到达目标城市。他们观察发现，如果几个人在旅途的某一段坐同一辆租的车，就可以减少总费用。你的任务就是找出这些人应该采取的路线使得租车的总费用最小。
　　我们假定：
　　1. 租一辆车的费用与它行驶的距离成正比，没有燃油、保险、乘客人数多于一个等产生的额外费用。
　　2. 所有车的费用与行驶距离的比例相同。
　　3. 一辆车可以容纳任意数量的乘客。
　　4. 任意一对城市之间最多只有一条道路直接相连，每条道路都是双向的且长度大于0。
　　5. 每个人的起始城市到目标城市都至少有一种路线。
　　6. 若多个人的路线中经过同一城市，则这些人从该城市到目标城市必乘同一辆车。
　　7. 一个人可以乘一辆车到某个城市，再乘另一辆车离开该城市。
输入格式
　　第一行包含三个整数nc, dc和nr，表示地图上的城市个数，目标城市的编号和地图上的道路条数。
　　接下来nr行每行包含三个整数c1, c2和dist，表示一条长度为dist的双向道路(c1, c2)。
　　接下来一行包含一个整数nj，表示人数。
　　接下来一行包含nj个整数，表示每个人的起始城市。
输出格式
　　第一行包含“distance = ”和一个整数，表示所租的车行驶的最小总距离。
　　接下来nj行每行包含一个人的访问路线，城市按访问顺序给出并用“-”连接。
　　存在多种方案时，选择需要访问到的城市集合元素最少的一种；仍然存在多种方案时，选择集合元素升序排列后字典序最小的一种。
样例输入
5 3 5
1 2 1
2 3 2
3 4 3
4 5 1
2 4 2
2
5 1
样例输出
distance = 6
5-4-2-3
1-2-3
样例输入
4 4 3
1 3 1
2 3 2
3 4 2
2
1 2
样例输出
distance = 5
1-3-4
2-3-4
样例输入
3 3 3
1 2 2
1 3 3
2 3 1
2
2 1
样例输出
distance = 3
2-3
1-2-3
数据规模和约定
　　对于30%的数据，1 <= nc <= 8。
　　对于100%的数据，1 <= nc <= 20，1 <= nj <= 10，1 <= dist <= 100。*/

