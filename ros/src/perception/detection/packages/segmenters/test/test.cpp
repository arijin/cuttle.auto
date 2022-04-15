int main(int argc, char** argv){
  ros::init(argc, argv, "pcd_rviz");

//-----single frame test-----
  char pcd_file[200];
  std::string pcd_name = "000000.pcd";
  sprintf(pcd_file, "%s/%s", root_dir.c_str(), pcd_name.c_str());

  std::string pcd_dir = pcd_file;
  pcl::PointCloud<PPoint>::Ptr cloudPPoint(new pcl::PointCloud<PPoint>);
  if (pcl::io::loadPCDFile<PPoint>(pcd_dir, *cloudPPoint)== -1)
  {
      PCL_ERROR("Couldn't read file test_pcd.pcd\n");
      return(-1);
  }
  sensor_msgs::PointCloud2 cloud_msg;
  pcl::toROSMsg(*cloudPPoint, cloud_msg);
  cloud_msg.header.frame_id = "Pandar20B";
  cloud_msg.header.stamp = ros::Time::now();
//--------------------------------

  std::cout << "start!" << std::endl;
  ros::Rate loop_rate(5);
  while (nh.ok()){
    boost::shared_ptr<sensor_msgs::PointCloud2> p = boost::make_shared<sensor_msgs::PointCloud2> (cloud_msg);
    cloud_callback(p);
    ros::spinOnce();
    loop_rate.sleep();
  }
  system("pause");
  return 0;
}
