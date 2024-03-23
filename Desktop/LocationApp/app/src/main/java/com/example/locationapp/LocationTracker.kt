import android.Manifest
import android.app.Activity
import android.content.Context
import android.content.pm.PackageManager
import android.location.Location
import android.location.LocationListener
import android.location.LocationManager
import android.os.Bundle
import android.util.Log
import androidx.appcompat.app.AppCompatActivity

class LocationTracker (val activity: Activity){


    companion object{
        const val TAG = "LocationTracker"
    }

    private val MIN_DISTANCE_CHANGE_FOR_UPDATES: Long = 1  //거리
    private val MIN_TIME_BW_UPDATES = (3000 * 1 * 1).toLong()  //시간

    val gpsListener: LocationListener = object : LocationListener {
        override fun onLocationChanged(location: Location) {
            Log.i(TAG, "GPS Location changed, onLocationChanged()")
            val latitude = location.latitude
            val longitude = location.longitude
            Log.i(TAG, "GPS Location changed, Latitude: $latitude" + ", Longitude: $longitude")
        }

        override fun onStatusChanged(provider: String, status: Int, extras: Bundle) {
            Log.i(TAG, "GPS Location changed, onStatusChanged()")
        }
        override fun onProviderEnabled(provider: String) {
            Log.i(TAG, "GPS Location changed, onProviderEnabled()")
        }
        override fun onProviderDisabled(provider: String) {
            Log.i(TAG, "GPS Location changed, onProviderDisabled()")
        }
    }
    val networkListener: LocationListener = object : LocationListener {
        override fun onLocationChanged(location: Location) {
            val latitude = location.latitude
            val longitude = location.longitude
            Log.i(TAG, "Network Location changed, Latitude: $latitude" + ", Longitude: $longitude")
        }

        override fun onStatusChanged(provider: String, status: Int, extras: Bundle) {
            Log.i(TAG, "Network Location changed, onStatusChanged()")
        }
        override fun onProviderEnabled(provider: String) {
            Log.i(TAG, "Network Location changed, onProviderEnabled()")
        }
        override fun onProviderDisabled(provider: String) {
            Log.i(TAG, "Network Location changed, onProviderDisabled()")
        }
    }

    fun getLocation(): Location? {
        val locationManager : LocationManager = activity.getSystemService(Context.LOCATION_SERVICE) as LocationManager
        val isGPSEnabled: Boolean = locationManager.isProviderEnabled(LocationManager.GPS_PROVIDER)
        val isNetworkEnabled: Boolean = locationManager.isProviderEnabled(LocationManager.NETWORK_PROVIDER)


        val hasFineLocationPermission : Int? = activity?.checkSelfPermission(Manifest.permission.ACCESS_FINE_LOCATION)
        val hasCoarseLocationPermission : Int? = activity?.checkSelfPermission(Manifest.permission.ACCESS_COARSE_LOCATION)

        var gpsLocation : Location? = null
        var networkLocation : Location? = null

        if(!(hasFineLocationPermission == PackageManager.PERMISSION_GRANTED )
            && !(hasCoarseLocationPermission == PackageManager.PERMISSION_GRANTED )){
            //없음
            Log.i(TAG,"위치 퍼미션 권한 없음")
        }else{

            if(!isGPSEnabled && !isNetworkEnabled){
                //없음
                Log.i(TAG,"GPS/Network Disable")
            }

            if(isGPSEnabled){
                locationManager.removeUpdates(gpsListener)
                locationManager.requestLocationUpdates(LocationManager.GPS_PROVIDER, MIN_TIME_BW_UPDATES.toLong(), MIN_DISTANCE_CHANGE_FOR_UPDATES.toFloat(), gpsListener)
                gpsLocation = locationManager.getLastKnownLocation(LocationManager.GPS_PROVIDER)
                Log.i(TAG, "GPS Loaction: ${gpsLocation?.latitude} / ${gpsLocation?.longitude}")
            }

            if(isNetworkEnabled){
                locationManager.removeUpdates(networkListener)
                locationManager.requestLocationUpdates(LocationManager.NETWORK_PROVIDER, MIN_TIME_BW_UPDATES.toLong(), MIN_DISTANCE_CHANGE_FOR_UPDATES.toFloat(), networkListener)
                networkLocation = locationManager.getLastKnownLocation(LocationManager.NETWORK_PROVIDER)
                Log.i(TAG, "Network Loaction: ${networkLocation?.latitude} / ${networkLocation?.longitude}")
            }

            if(gpsLocation == null && networkLocation ==null){
                //return null
            }else if(gpsLocation != null){
                return gpsLocation
            }else if(networkLocation != null){
                return networkLocation
            }
        }
        val defaultLocation : Location = Location("영등포구 의사당대로 141")
        defaultLocation.latitude = 37.51953
        defaultLocation.longitude = 126.92742
        return defaultLocation
    }

}
출처: https://helloit.tistory.com/340 [IT 이야기:티스토리]