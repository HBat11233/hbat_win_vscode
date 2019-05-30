// pages/search/search.js

const app = getApp()

function getRad(d) {
  var PI = Math.PI;
  return d * PI / 180.0;
}

/**
 * 获取两个经纬度之间的距离
 * @param lat1 第一点的纬度
 * @param lng1 第一点的经度
 * @param lat2 第二点的纬度
 * @param lng2 第二点的经度
 * @returns {Number}
 */

function getDistance(lat1, lng1, lat2, lng2) {
  var f = getRad((lat1 + lat2) / 2);
  var g = getRad((lat1 - lat2) / 2);
  var l = getRad((lng1 - lng2) / 2);
  var sg = Math.sin(g);
  var sl = Math.sin(l);
  var sf = Math.sin(f);
  var s, c, w, r, d, h1, h2;
  var a = 6378137.0;//The Radius of eath in meter.   
  var fl = 1 / 298.257;
  sg = sg * sg;
  sl = sl * sl;
  sf = sf * sf;
  s = sg * (1 - sl) + (1 - sf) * sl;
  c = (1 - sg) * (1 - sl) + sf * sl;
  w = Math.atan(Math.sqrt(s / c));
  r = Math.sqrt(s * c) / w;
  d = 2 * w * a;
  h1 = (3 * r - 1) / 2 / c;
  h2 = (3 * r + 1) / 2 / s;
  s = d * (1 + fl * (h1 * sf * (1 - sg) - h2 * (1 - sf) * sg));
  s = s / 1000;
  s = s.toFixed(2);//指定小数点后的位数。   
  return s;
}

Page({

  /**
   * 页面的初始数据
   */
  data: {
    latitude:'',
    longitude:'',
    speed:'',
    accuracy:'',
    cardx:50,
    cardy:50
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
    this.updataLocation();
  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {
    
  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow: function () {

  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide: function () {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload: function () {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh: function () {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom: function () {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage: function () {

  },

  /**
   * 刷新位置信息
   */
  updataLocation: function() {
    wx.getLocation({
      type: 'gcj02',
      altitude: true,
      success: res => {
        const latitude = res.latitude
        const longitude = res.longitude
        //app.globalData.myip={latitude:latitude,longitude:longitude}
        this.setData({
          latitude:res.latitude,
          longitude:res.longitude,
          speed:res.speed,
          accuracy:res.accuracy,
          altitude:res.altitude,
          markers:[{
            iconPath:'/ico/ddw.png',
            id: 0,
            latitude: res.latitude,
            longitude: res.longitude,
            width: 25,
            height: 25
          }],
          circles:[{
            latitude:res.latitude,
            longitude:res.longitude,
            radius:res.accuracy,
            fillColor: '#0000ff'
          }]
        })
      this.onGetData()
      }
    })
  },

  onGetData: function () {
    // 调用云函数
    wx.cloud.callFunction({
      name: 'getcard',
      data: {},
      success: res => {
        console.log('data size: ', res.result.data.length)
        var tempimpath={}
        for(var i=0;i<res.result.data.length;++i)
        {
          var temp={
            iconPath:'/ico/ddw.png',
            id: i+1,
            latitude: res.result.data[i].location.latitude,
            longitude: res.result.data[i].location.longitude,
            width: 25,
            height: 25
          }
          //console.log(res.result.data[i].location)
          wx.cloud.getTempFileURL({
            fileList:res.result.data[i].fileid,
            success: res => {
              console.log('图片获取成功')
              for(var k=0;k<res.fileList.length;++k)
                tempimpath[res.fileList[k].fileID]=res.fileList[k].tempFileURL
              this.setData({
                tempimpath:tempimpath
              })
              //console.log('gettempfileurl',tempimpath)
            },
            fail: err => {
              console.log('图片获取失败')
            }
          })
          this.data.markers.push(temp)
          //console.log('callfuncation:',tempimpath)
        }
        var temp=this.data.markers
        //console.log(temp)
        var tempclouddata={data:[]}
        for(var i=0;i<res.result.data.length;++i)
        {
          var len = getDistance(res.result.data[i].location.latitude, res.result.data[i].location.longitude, this.data.latitude, this.data.longitude)*1000
          if(isNaN(len))
            len=0;
          console.log(res.result.data[i].find,len)
          console.log((res.result.data[i].find === 1))
          if ((res.result.data[i].find === 0 && len < 200) || (res.result.data[i].find === '1' && len < 100) || (res.result.data[i].find === '2' && len < 50))
          {
            console.log(len)
            tempclouddata.data.push(res.result.data[i])
          }
        }
        this.setData({
          markers:temp,
          clouddata: tempclouddata
        })

        //app.globalData.openid = res.result.openid
        //wx.navigateTo({
        //  url: '../userConsole/userConsole',
        //})
      },
      fail: err => {
        console.error('[云函数] [login] 调用失败', err)
        //wx.navigateTo({
        //  url: '../deployFunctions/deployFunctions',
        //})
      }
    })
  },

  toimage: function (res) {
    app.globalData.imageid=res.currentTarget.id;
  },

  toWord:function (res) {
    app.globalData.clouddata=this.data.clouddata
    app.globalData.tempimpath=this.data.tempimpath
    app.globalData.wordid=res.currentTarget.id
    console.log(res.currentTarget.id)
  }
})