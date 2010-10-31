#ifndef _OPENNERO_AI_SENSOR_RADARSENSOR_H_
#define _OPENNERO_AI_SENSOR_RADARSENSOR_H_

#include "core/Common.h"
#include "ai/sensors/Sensor.h"

namespace OpenNero
{
    BOOST_SHARED_DECL(RadarSensor);

    class RadarSensor : public Sensor {
    private:
        //! least relative yaw (degrees) of objects to include
        double leftbound;
        
        //! greatest relative yaw (degrees) of objects to include
        double rightbound;
        
        //! least relative pitch (degrees) of objects to include
        double bottombound;
        
        //! greatest relative pitch (degrees) of objects to include
        double topbound;

        //! the radius of the radar sector (how far it extends)
        double radius;
        
    public:
        RadarSensor()
            : Sensor()
            , leftbound(0), rightbound(0)
            , bottombound(0), topbound(0)
            , radius(0)
        {}
    
        //! Create a new RadarSensor
        //! @param leftbound least relative yaw (degrees) of objects to include
        //! @param rightbound greatest relative yaw (degrees) of objects to include
        //! @param bottombound least relative pitch (degrees) of objects to include
        //! @param topbound greatest relative pitch (degrees) of objects to include
        //! @param radius the radius of the radar sector (how far it extends)
        RadarSensor(
            double leftbound, double rightbound, 
            double bottombound, double topbound, 
            double radius, 
            U32 types = 0);
        
        virtual ~RadarSensor();
    
        //! Get the region of interest for this sensor
        virtual BBoxf getBoundingBox();
        
        //! get the minimal possible observation
        virtual double getMin();
        
        //! get the maximum possible observation
        virtual double getMax();

        //! Process an object of interest
        virtual bool process(SimEntityPtr ent);
        
        //! Get the value computed for this sensor
        virtual double getObservation();

        friend std::ostream& operator<<(std::ostream& in, const RadarSensor& rs);

    protected:

        void toXMLParams(std::ostream& out) const;

    };
}

#endif /* _OPENNERO_AI_SENSOR_RADARSENSOR_H_ */
