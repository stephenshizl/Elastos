
#ifndef __ELASTOS_DROID_HARDWARE_CAMERA2_CAPTUREREQUEST_H__
#define __ELASTOS_DROID_HARDWARE_CAMERA2_CAPTUREREQUEST_H__

#include <Elastos.CoreLibrary.Utility.h>
#include "elastos/droid/ext/frameworkext.h"
#include "elastos/droid/hardware/camera2/CameraMetadata.h"
#include <elastos/core/Object.h>

using Elastos::Droid::Hardware::Camera2::Impl::ICameraMetadataNative;
using Elastos::Droid::Hardware::Camera2::Impl::ICameraMetadataNativeKey;
using Elastos::Droid::Hardware::Camera2::Utils::ITypeReference;
using Elastos::Droid::View::ISurface;
using Elastos::Core::Object;
using Elastos::Utility::ICollection;
using Elastos::Utility::IHashSet;

namespace Elastos {
namespace Droid {
namespace Hardware {
namespace Camera2 {

class CaptureRequest
    : public CameraMetadata
    , public ICaptureRequest
    , public IParcelable
{
public:
    class Key
        : public Object
        , public ICaptureRequestKey
    {
    public:
        CAR_INTERFACE_DECL()

        Key();

        virtual ~Key() {}

        CARAPI constructor();

        /**
         * Visible for testing and vendor extensions only.
         *
         * @hide
         */
        CARAPI constructor(
            /* [in] */ const String& name,
            /* [in] */ ClassID type);

        /**
         * Visible for testing and vendor extensions only.
         *
         * @hide
         */
        CARAPI constructor(
            /* [in] */ const String& name,
            /* [in] */ ITypeReference* typeReference);

        //@SuppressWarnings({ "unchecked" })
        CARAPI constructor(
            /* [in] */ ICameraMetadataNativeKey* nativeKey);

        /**
         * Return a camelCase, period separated name formatted like:
         * {@code "root.section[.subsections].name"}.
         *
         * <p>Built-in keys exposed by the Android SDK are always prefixed with {@code "android."};
         * keys that are device/platform-specific are prefixed with {@code "com."}.</p>
         *
         * <p>For example, {@code CameraCharacteristics.SCALER_STREAM_CONFIGURATION_MAP} would
         * have a name of {@code "android.scaler.streamConfigurationMap"}; whereas a device
         * specific key might look like {@code "com.google.nexus.data.private"}.</p>
         *
         * @return String representation of the key name
         */
        CARAPI GetName(
            /* [out] */ String* name);

        /**
         * {@inheritDoc}
         */
        //@Override
        CARAPI GetHashCode(
            /* [out] */ Int32* code);

        /**
         * {@inheritDoc}
         */
        // @SuppressWarnings("unchecked")
        // @Override
        CARAPI Equals(
            /* [in] */ IInterface* obj,
            /* [out] */ Boolean* e);

        /**
         * Visible for CameraMetadataNative implementation only; do not use.
         *
         * TODO: Make this private or remove it altogether.
         *
         * @hide
         */
        CARAPI GetNativeKey(
            /* [out] */ ICameraMetadataNativeKey** key);

    private:
        friend class CaptureRequest;
        //@SuppressWarnings({ "unchecked" })
        Key(
            /* [in] */ ICameraMetadataNativeKey* nativeKey);

        Key(
            /* [in] */ const String& name,
            /* [in] */ ClassID type);

    private:
        AutoPtr<ICameraMetadataNativeKey> mKey;
    };

    class Builder
        : public Object
        , public ICaptureRequestBuilder
    {
    public:
        CAR_INTERFACE_DECL()

        Builder();

        virtual ~Builder() {}

        CARAPI constructor();

        /**
         * Initialize the builder using the template; the request takes
         * ownership of the template.
         *
         * @hide
         */
        CARAPI constructor(
            /* [in] */ ICameraMetadataNative* _template);

        /**
         * <p>Add a surface to the list of targets for this request</p>
         *
         * <p>The Surface added must be one of the surfaces included in the most
         * recent call to {@link CameraDevice#createCaptureSession}, when the
         * request is given to the camera device.</p>
         *
         * <p>Adding a target more than once has no effect.</p>
         *
         * @param outputTarget Surface to use as an output target for this request
         */
        CARAPI AddTarget(
            /* [in] */ ISurface* outputTarget);

        /**
         * <p>Remove a surface from the list of targets for this request.</p>
         *
         * <p>Removing a target that is not currently added has no effect.</p>
         *
         * @param outputTarget Surface to use as an output target for this request
         */
        CARAPI RemoveTarget(
            /* [in] */ ISurface* outputTarget);

        /**
         * Set a capture request field to a value. The field definitions can be
         * found in {@link CaptureRequest}.
         *
         * @param key The metadata field to write.
         * @param value The value to set the field to, which must be of a matching
         * type to the key.
         */
        CARAPI Set(
            /* [in] */ ICaptureRequestKey* key,
            /* [in] */ IInterface* value);

        /**
         * Get a capture request field value. The field definitions can be
         * found in {@link CaptureRequest}.
         *
         * @throws IllegalArgumentException if the key was not valid
         *
         * @param key The metadata field to read.
         * @return The value of that key, or {@code null} if the field is not set.
         */
        CARAPI Get(
            /* [in] */ ICaptureRequestKey* key,
            /* [out] */ IInterface** result);

        /**
         * Set a tag for this request.
         *
         * <p>This tag is not used for anything by the camera device, but can be
         * used by an application to easily identify a CaptureRequest when it is
         * returned by
         * {@link CameraCaptureSession.CaptureCallback#onCaptureCompleted CaptureCallback.onCaptureCompleted}
         *
         * @param tag an arbitrary Object to store with this request
         * @see CaptureRequest#getTag
         */
        CARAPI SetTag(
            /* [in] */ IInterface* tag);

        /**
         * Build a request using the current target Surfaces and settings.
         * <p>Note that, although it is possible to create a {@code CaptureRequest} with no target
         * {@link Surface}s, passing such a request into {@link CameraCaptureSession#capture},
         * {@link CameraCaptureSession#captureBurst},
         * {@link CameraCaptureSession#setRepeatingBurst}, or
         * {@link CameraCaptureSession#setRepeatingRequest} will cause that method to throw an
         * {@link IllegalArgumentException}.</p>
         *
         * @return A new capture request instance, ready for submission to the
         * camera device.
         */
        CARAPI Build(
            /* [out] */ ICaptureRequest** result);

        /**
         * @hide
         */
        CARAPI IsEmpty(
            /* [out] */ Boolean* result);

    private:
        AutoPtr<ICaptureRequest> mRequest;
    };

public:
    CAR_INTERFACE_DECL()

    virtual ~CaptureRequest() {}

    CARAPI Get(
        /* [in] */ ICaptureRequestKey* key,
        /* [out] */ IInterface** face);

    /**
     * @hide
     */
    CARAPI GetTargets(
        /* [out] */ ICollection** targets);

    /**
     * {@inheritDoc}
     * @hide
     */
    // @SuppressWarnings("unchecked")
    // @Override
    CARAPI GetProtected(
        /* [in] */ IInterface* key,
        /* [out] */ IInterface** outface);

    /**
     * {@inheritDoc}
     * @hide
     */
    // @SuppressWarnings("unchecked")
    // @Override
    CARAPI GetKeyClass(
        /* [out] */ ClassID* id);

    /**
     * {@inheritDoc}
     */
    //@Override
    CARAPI GetKeys(
        /* [out] */ IList** outlist);

    /**
     * Retrieve the tag for this request, if any.
     *
     * <p>This tag is not used for anything by the camera device, but can be
     * used by an application to easily identify a CaptureRequest when it is
     * returned by
     * {@link CameraCaptureSession.CaptureCallback#onCaptureCompleted CaptureCallback.onCaptureCompleted}
     * </p>
     *
     * @return the last tag Object set on this request, or {@code null} if
     *     no tag has been set.
     * @see Builder#setTag
     */
    CARAPI GetTag(
        /* [out] */ IInterface** tag);

    /**
     * Determine whether this CaptureRequest is equal to another CaptureRequest.
     *
     * <p>A request is considered equal to another is if it's set of key/values is equal, it's
     * list of output surfaces is equal, and the user tag is equal.</p>
     *
     * @param other Another instance of CaptureRequest.
     *
     * @return True if the requests are the same, false otherwise.
     */
    //@Override
    CARAPI Equals(
        /* [in] */ IInterface* other,
        /* [out] */ Boolean* result);

    //@Override
    CARAPI GetHashCode(
        /* [out] */ Int32* code);

    //@Override
    CARAPI WriteToParcel(
        /* [in] */ IParcel* dest);

    //@Override
    CARAPI ReadFromParcel(
        /* [in] */ IParcel* source);

    /**
     * @hide
     */
    CARAPI ContainsTarget(
        /* [in] */ ISurface* surface,
        /* [out] */ Boolean* result);

    // public static final Parcelable.Creator<CaptureRequest> CREATOR =
    //         new Parcelable.Creator<CaptureRequest>() {
    //     @Override
    //     public CaptureRequest createFromParcel(Parcel in) {
    //         CaptureRequest request = new CaptureRequest();
    //         request.readFromParcel(in);

    //         return request;
    //     }

    //     @Override
    //     public CaptureRequest[] newArray(int size) {
    //         return new CaptureRequest[size];
    //     }
    // };

private:
    friend class CaptureRequestBuilder;
    /**
     * Construct empty request.
     *
     * Used by Binder to unparcel this object only.
     */
    CaptureRequest();

    /**
     * Clone from source capture request.
     *
     * Used by the Builder to create an immutable copy.
     */
    //@SuppressWarnings("unchecked")
    CaptureRequest(
        /* [in] */ ICaptureRequest* source);

    /**
     * Take ownership of passed-in settings.
     *
     * Used by the Builder to create a mutable CaptureRequest.
     */
    CaptureRequest(
        /* [in] */ ICameraMetadataNative* settings);


    CARAPI Equals(
        /* [in] */ ICaptureRequest* other,
        /* [out] */ Boolean* result);

public:
    /*@O~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~
     * The key entries below this point are generated from metadata
     * definitions in /system/media/camera/docs. Do not modify by hand or
     * modify the comment blocks at the start or end.
     *~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~*/

    /**
     * <p>The mode control selects how the image data is converted from the
     * sensor's native color into linear sRGB color.</p>
     * <p>When auto-white balance (AWB) is enabled with {@link CaptureRequest#CONTROL_AWB_MODE android.control.awbMode}, this
     * control is overridden by the AWB routine. When AWB is disabled, the
     * application controls how the color mapping is performed.</p>
     * <p>We define the expected processing pipeline below. For consistency
     * across devices, this is always the case with TRANSFORM_MATRIX.</p>
     * <p>When either FULL or HIGH_QUALITY is used, the camera device may
     * do additional processing but {@link CaptureRequest#COLOR_CORRECTION_GAINS android.colorCorrection.gains} and
     * {@link CaptureRequest#COLOR_CORRECTION_TRANSFORM android.colorCorrection.transform} will still be provided by the
     * camera device (in the results) and be roughly correct.</p>
     * <p>Switching to TRANSFORM_MATRIX and using the data provided from
     * FAST or HIGH_QUALITY will yield a picture with the same white point
     * as what was produced by the camera device in the earlier frame.</p>
     * <p>The expected processing pipeline is as follows:</p>
     * <p><img alt="White balance processing pipeline" src="../../../../images/camera2/metadata/android.colorCorrection.mode/processing_pipeline.png" /></p>
     * <p>The white balance is encoded by two values, a 4-channel white-balance
     * gain vector (applied in the Bayer domain), and a 3x3 color transform
     * matrix (applied after demosaic).</p>
     * <p>The 4-channel white-balance gains are defined as:</p>
     * <pre><code>{@link CaptureRequest#COLOR_CORRECTION_GAINS android.colorCorrection.gains} = [ R G_even G_odd B ]
     * </code></pre>
     * <p>where <code>G_even</code> is the gain for green pixels on even rows of the
     * output, and <code>G_odd</code> is the gain for green pixels on the odd rows.
     * These may be identical for a given camera device implementation; if
     * the camera device does not support a separate gain for even/odd green
     * channels, it will use the <code>G_even</code> value, and write <code>G_odd</code> equal to
     * <code>G_even</code> in the output result metadata.</p>
     * <p>The matrices for color transforms are defined as a 9-entry vector:</p>
     * <pre><code>{@link CaptureRequest#COLOR_CORRECTION_TRANSFORM android.colorCorrection.transform} = [ I0 I1 I2 I3 I4 I5 I6 I7 I8 ]
     * </code></pre>
     * <p>which define a transform from input sensor colors, <code>P_in = [ r g b ]</code>,
     * to output linear sRGB, <code>P_out = [ r' g' b' ]</code>,</p>
     * <p>with colors as follows:</p>
     * <pre><code>r' = I0r + I1g + I2b
     * g' = I3r + I4g + I5b
     * b' = I6r + I7g + I8b
     * </code></pre>
     * <p>Both the input and output value ranges must match. Overflow/underflow
     * values are clipped to fit within the range.</p>
     * <p><b>Possible values:</b>
     * <ul>
     *   <li>{@link #COLOR_CORRECTION_MODE_TRANSFORM_MATRIX TRANSFORM_MATRIX}</li>
     *   <li>{@link #COLOR_CORRECTION_MODE_FAST FAST}</li>
     *   <li>{@link #COLOR_CORRECTION_MODE_HIGH_QUALITY HIGH_QUALITY}</li>
     * </ul></p>
     * <p><b>Optional</b> - This value may be {@code null} on some devices.</p>
     * <p><b>Full capability</b> -
     * Present on all camera devices that report being {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL_FULL HARDWARE_LEVEL_FULL} devices in the
     * {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL android.info.supportedHardwareLevel} key</p>
     *
     * @see CaptureRequest#COLOR_CORRECTION_GAINS
     * @see CaptureRequest#COLOR_CORRECTION_TRANSFORM
     * @see CaptureRequest#CONTROL_AWB_MODE
     * @see CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL
     * @see #COLOR_CORRECTION_MODE_TRANSFORM_MATRIX
     * @see #COLOR_CORRECTION_MODE_FAST
     * @see #COLOR_CORRECTION_MODE_HIGH_QUALITY
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> COLOR_CORRECTION_MODE;

    /**
     * <p>A color transform matrix to use to transform
     * from sensor RGB color space to output linear sRGB color space.</p>
     * <p>This matrix is either set by the camera device when the request
     * {@link CaptureRequest#COLOR_CORRECTION_MODE android.colorCorrection.mode} is not TRANSFORM_MATRIX, or
     * directly by the application in the request when the
     * {@link CaptureRequest#COLOR_CORRECTION_MODE android.colorCorrection.mode} is TRANSFORM_MATRIX.</p>
     * <p>In the latter case, the camera device may round the matrix to account
     * for precision issues; the final rounded matrix should be reported back
     * in this matrix result metadata. The transform should keep the magnitude
     * of the output color values within <code>[0, 1.0]</code> (assuming input color
     * values is within the normalized range <code>[0, 1.0]</code>), or clipping may occur.</p>
     * <p><b>Units</b>: Unitless scale factors</p>
     * <p><b>Optional</b> - This value may be {@code null} on some devices.</p>
     * <p><b>Full capability</b> -
     * Present on all camera devices that report being {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL_FULL HARDWARE_LEVEL_FULL} devices in the
     * {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL android.info.supportedHardwareLevel} key</p>
     *
     * @see CaptureRequest#COLOR_CORRECTION_MODE
     * @see CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> COLOR_CORRECTION_TRANSFORM;

    /**
     * <p>Gains applying to Bayer raw color channels for
     * white-balance.</p>
     * <p>These per-channel gains are either set by the camera device
     * when the request {@link CaptureRequest#COLOR_CORRECTION_MODE android.colorCorrection.mode} is not
     * TRANSFORM_MATRIX, or directly by the application in the
     * request when the {@link CaptureRequest#COLOR_CORRECTION_MODE android.colorCorrection.mode} is
     * TRANSFORM_MATRIX.</p>
     * <p>The gains in the result metadata are the gains actually
     * applied by the camera device to the current frame.</p>
     * <p><b>Units</b>: Unitless gain factors</p>
     * <p><b>Optional</b> - This value may be {@code null} on some devices.</p>
     * <p><b>Full capability</b> -
     * Present on all camera devices that report being {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL_FULL HARDWARE_LEVEL_FULL} devices in the
     * {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL android.info.supportedHardwareLevel} key</p>
     *
     * @see CaptureRequest#COLOR_CORRECTION_MODE
     * @see CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> COLOR_CORRECTION_GAINS;

    /**
     * <p>Mode of operation for the chromatic aberration correction algorithm.</p>
     * <p>Chromatic (color) aberration is caused by the fact that different wavelengths of light
     * can not focus on the same point after exiting from the lens. This metadata defines
     * the high level control of chromatic aberration correction algorithm, which aims to
     * minimize the chromatic artifacts that may occur along the object boundaries in an
     * image.</p>
     * <p>FAST/HIGH_QUALITY both mean that camera device determined aberration
     * correction will be applied. HIGH_QUALITY mode indicates that the camera device will
     * use the highest-quality aberration correction algorithms, even if it slows down
     * capture rate. FAST means the camera device will not slow down capture rate when
     * applying aberration correction.</p>
     * <p>LEGACY devices will always be in FAST mode.</p>
     * <p><b>Possible values:</b>
     * <ul>
     *   <li>{@link #COLOR_CORRECTION_ABERRATION_MODE_OFF OFF}</li>
     *   <li>{@link #COLOR_CORRECTION_ABERRATION_MODE_FAST FAST}</li>
     *   <li>{@link #COLOR_CORRECTION_ABERRATION_MODE_HIGH_QUALITY HIGH_QUALITY}</li>
     * </ul></p>
     * <p><b>Available values for this device:</b><br>
     * {@link CameraCharacteristics#COLOR_CORRECTION_AVAILABLE_ABERRATION_MODES android.colorCorrection.availableAberrationModes}</p>
     * <p>This key is available on all devices.</p>
     *
     * @see CameraCharacteristics#COLOR_CORRECTION_AVAILABLE_ABERRATION_MODES
     * @see #COLOR_CORRECTION_ABERRATION_MODE_OFF
     * @see #COLOR_CORRECTION_ABERRATION_MODE_FAST
     * @see #COLOR_CORRECTION_ABERRATION_MODE_HIGH_QUALITY
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> COLOR_CORRECTION_ABERRATION_MODE;

    /**
     * <p>The desired setting for the camera device's auto-exposure
     * algorithm's antibanding compensation.</p>
     * <p>Some kinds of lighting fixtures, such as some fluorescent
     * lights, flicker at the rate of the power supply frequency
     * (60Hz or 50Hz, depending on country). While this is
     * typically not noticeable to a person, it can be visible to
     * a camera device. If a camera sets its exposure time to the
     * wrong value, the flicker may become visible in the
     * viewfinder as flicker or in a final captured image, as a
     * set of variable-brightness bands across the image.</p>
     * <p>Therefore, the auto-exposure routines of camera devices
     * include antibanding routines that ensure that the chosen
     * exposure value will not cause such banding. The choice of
     * exposure time depends on the rate of flicker, which the
     * camera device can detect automatically, or the expected
     * rate can be selected by the application using this
     * control.</p>
     * <p>A given camera device may not support all of the possible
     * options for the antibanding mode. The
     * {@link CameraCharacteristics#CONTROL_AE_AVAILABLE_ANTIBANDING_MODES android.control.aeAvailableAntibandingModes} key contains
     * the available modes for a given camera device.</p>
     * <p>The default mode is AUTO, which is supported by all
     * camera devices.</p>
     * <p>If manual exposure control is enabled (by setting
     * {@link CaptureRequest#CONTROL_AE_MODE android.control.aeMode} or {@link CaptureRequest#CONTROL_MODE android.control.mode} to OFF),
     * then this setting has no effect, and the application must
     * ensure it selects exposure times that do not cause banding
     * issues. The {@link CaptureResult#STATISTICS_SCENE_FLICKER android.statistics.sceneFlicker} key can assist
     * the application in this.</p>
     * <p><b>Possible values:</b>
     * <ul>
     *   <li>{@link #CONTROL_AE_ANTIBANDING_MODE_OFF OFF}</li>
     *   <li>{@link #CONTROL_AE_ANTIBANDING_MODE_50HZ 50HZ}</li>
     *   <li>{@link #CONTROL_AE_ANTIBANDING_MODE_60HZ 60HZ}</li>
     *   <li>{@link #CONTROL_AE_ANTIBANDING_MODE_AUTO AUTO}</li>
     * </ul></p>
     * <p><b>Available values for this device:</b><br></p>
     * <p>{@link CameraCharacteristics#CONTROL_AE_AVAILABLE_ANTIBANDING_MODES android.control.aeAvailableAntibandingModes}</p>
     * <p>This key is available on all devices.</p>
     *
     * @see CameraCharacteristics#CONTROL_AE_AVAILABLE_ANTIBANDING_MODES
     * @see CaptureRequest#CONTROL_AE_MODE
     * @see CaptureRequest#CONTROL_MODE
     * @see CaptureResult#STATISTICS_SCENE_FLICKER
     * @see #CONTROL_AE_ANTIBANDING_MODE_OFF
     * @see #CONTROL_AE_ANTIBANDING_MODE_50HZ
     * @see #CONTROL_AE_ANTIBANDING_MODE_60HZ
     * @see #CONTROL_AE_ANTIBANDING_MODE_AUTO
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> CONTROL_AE_ANTIBANDING_MODE;

    /**
     * <p>Adjustment to auto-exposure (AE) target image
     * brightness.</p>
     * <p>The adjustment is measured as a count of steps, with the
     * step size defined by {@link CameraCharacteristics#CONTROL_AE_COMPENSATION_STEP android.control.aeCompensationStep} and the
     * allowed range by {@link CameraCharacteristics#CONTROL_AE_COMPENSATION_RANGE android.control.aeCompensationRange}.</p>
     * <p>For example, if the exposure value (EV) step is 0.333, '6'
     * will mean an exposure compensation of +2 EV; -3 will mean an
     * exposure compensation of -1 EV. One EV represents a doubling
     * of image brightness. Note that this control will only be
     * effective if {@link CaptureRequest#CONTROL_AE_MODE android.control.aeMode} <code>!=</code> OFF. This control
     * will take effect even when {@link CaptureRequest#CONTROL_AE_LOCK android.control.aeLock} <code>== true</code>.</p>
     * <p>In the event of exposure compensation value being changed, camera device
     * may take several frames to reach the newly requested exposure target.
     * During that time, {@link CaptureResult#CONTROL_AE_STATE android.control.aeState} field will be in the SEARCHING
     * state. Once the new exposure target is reached, {@link CaptureResult#CONTROL_AE_STATE android.control.aeState} will
     * change from SEARCHING to either CONVERGED, LOCKED (if AE lock is enabled), or
     * FLASH_REQUIRED (if the scene is too dark for still capture).</p>
     * <p><b>Units</b>: Compensation steps</p>
     * <p><b>Range of valid values:</b><br>
     * {@link CameraCharacteristics#CONTROL_AE_COMPENSATION_RANGE android.control.aeCompensationRange}</p>
     * <p>This key is available on all devices.</p>
     *
     * @see CameraCharacteristics#CONTROL_AE_COMPENSATION_RANGE
     * @see CameraCharacteristics#CONTROL_AE_COMPENSATION_STEP
     * @see CaptureRequest#CONTROL_AE_LOCK
     * @see CaptureRequest#CONTROL_AE_MODE
     * @see CaptureResult#CONTROL_AE_STATE
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> CONTROL_AE_EXPOSURE_COMPENSATION;

    /**
     * <p>Whether auto-exposure (AE) is currently locked to its latest
     * calculated values.</p>
     * <p>When set to <code>true</code> (ON), the AE algorithm is locked to its latest parameters,
     * and will not change exposure settings until the lock is set to <code>false</code> (OFF).</p>
     * <p>Note that even when AE is locked, the flash may be fired if
     * the {@link CaptureRequest#CONTROL_AE_MODE android.control.aeMode} is ON_AUTO_FLASH /
     * ON_ALWAYS_FLASH / ON_AUTO_FLASH_REDEYE.</p>
     * <p>When {@link CaptureRequest#CONTROL_AE_EXPOSURE_COMPENSATION android.control.aeExposureCompensation} is changed, even if the AE lock
     * is ON, the camera device will still adjust its exposure value.</p>
     * <p>If AE precapture is triggered (see {@link CaptureRequest#CONTROL_AE_PRECAPTURE_TRIGGER android.control.aePrecaptureTrigger})
     * when AE is already locked, the camera device will not change the exposure time
     * ({@link CaptureRequest#SENSOR_EXPOSURE_TIME android.sensor.exposureTime}) and sensitivity ({@link CaptureRequest#SENSOR_SENSITIVITY android.sensor.sensitivity})
     * parameters. The flash may be fired if the {@link CaptureRequest#CONTROL_AE_MODE android.control.aeMode}
     * is ON_AUTO_FLASH/ON_AUTO_FLASH_REDEYE and the scene is too dark. If the
     * {@link CaptureRequest#CONTROL_AE_MODE android.control.aeMode} is ON_ALWAYS_FLASH, the scene may become overexposed.</p>
     * <p>Since the camera device has a pipeline of in-flight requests, the settings that
     * get locked do not necessarily correspond to the settings that were present in the
     * latest capture result received from the camera device, since additional captures
     * and AE updates may have occurred even before the result was sent out. If an
     * application is switching between automatic and manual control and wishes to eliminate
     * any flicker during the switch, the following procedure is recommended:</p>
     * <ol>
     * <li>Starting in auto-AE mode:</li>
     * <li>Lock AE</li>
     * <li>Wait for the first result to be output that has the AE locked</li>
     * <li>Copy exposure settings from that result into a request, set the request to manual AE</li>
     * <li>Submit the capture request, proceed to run manual AE as desired.</li>
     * </ol>
     * <p>See {@link CaptureResult#CONTROL_AE_STATE android.control.aeState} for AE lock related state transition details.</p>
     * <p>This key is available on all devices.</p>
     *
     * @see CaptureRequest#CONTROL_AE_EXPOSURE_COMPENSATION
     * @see CaptureRequest#CONTROL_AE_MODE
     * @see CaptureRequest#CONTROL_AE_PRECAPTURE_TRIGGER
     * @see CaptureResult#CONTROL_AE_STATE
     * @see CaptureRequest#SENSOR_EXPOSURE_TIME
     * @see CaptureRequest#SENSOR_SENSITIVITY
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> CONTROL_AE_LOCK;

    /**
     * <p>The desired mode for the camera device's
     * auto-exposure routine.</p>
     * <p>This control is only effective if {@link CaptureRequest#CONTROL_MODE android.control.mode} is
     * AUTO.</p>
     * <p>When set to any of the ON modes, the camera device's
     * auto-exposure routine is enabled, overriding the
     * application's selected exposure time, sensor sensitivity,
     * and frame duration ({@link CaptureRequest#SENSOR_EXPOSURE_TIME android.sensor.exposureTime},
     * {@link CaptureRequest#SENSOR_SENSITIVITY android.sensor.sensitivity}, and
     * {@link CaptureRequest#SENSOR_FRAME_DURATION android.sensor.frameDuration}). If one of the FLASH modes
     * is selected, the camera device's flash unit controls are
     * also overridden.</p>
     * <p>The FLASH modes are only available if the camera device
     * has a flash unit ({@link CameraCharacteristics#FLASH_INFO_AVAILABLE android.flash.info.available} is <code>true</code>).</p>
     * <p>If flash TORCH mode is desired, this field must be set to
     * ON or OFF, and {@link CaptureRequest#FLASH_MODE android.flash.mode} set to TORCH.</p>
     * <p>When set to any of the ON modes, the values chosen by the
     * camera device auto-exposure routine for the overridden
     * fields for a given capture will be available in its
     * CaptureResult.</p>
     * <p><b>Possible values:</b>
     * <ul>
     *   <li>{@link #CONTROL_AE_MODE_OFF OFF}</li>
     *   <li>{@link #CONTROL_AE_MODE_ON ON}</li>
     *   <li>{@link #CONTROL_AE_MODE_ON_AUTO_FLASH ON_AUTO_FLASH}</li>
     *   <li>{@link #CONTROL_AE_MODE_ON_ALWAYS_FLASH ON_ALWAYS_FLASH}</li>
     *   <li>{@link #CONTROL_AE_MODE_ON_AUTO_FLASH_REDEYE ON_AUTO_FLASH_REDEYE}</li>
     * </ul></p>
     * <p><b>Available values for this device:</b><br>
     * {@link CameraCharacteristics#CONTROL_AE_AVAILABLE_MODES android.control.aeAvailableModes}</p>
     * <p>This key is available on all devices.</p>
     *
     * @see CameraCharacteristics#CONTROL_AE_AVAILABLE_MODES
     * @see CaptureRequest#CONTROL_MODE
     * @see CameraCharacteristics#FLASH_INFO_AVAILABLE
     * @see CaptureRequest#FLASH_MODE
     * @see CaptureRequest#SENSOR_EXPOSURE_TIME
     * @see CaptureRequest#SENSOR_FRAME_DURATION
     * @see CaptureRequest#SENSOR_SENSITIVITY
     * @see #CONTROL_AE_MODE_OFF
     * @see #CONTROL_AE_MODE_ON
     * @see #CONTROL_AE_MODE_ON_AUTO_FLASH
     * @see #CONTROL_AE_MODE_ON_ALWAYS_FLASH
     * @see #CONTROL_AE_MODE_ON_AUTO_FLASH_REDEYE
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> CONTROL_AE_MODE;

    /**
     * <p>List of metering areas to use for auto-exposure adjustment.</p>
     * <p>Not available if {@link CameraCharacteristics#CONTROL_MAX_REGIONS_AE android.control.maxRegionsAe} is 0.
     * Otherwise will always be present.</p>
     * <p>The maximum number of regions supported by the device is determined by the value
     * of {@link CameraCharacteristics#CONTROL_MAX_REGIONS_AE android.control.maxRegionsAe}.</p>
     * <p>The coordinate system is based on the active pixel array,
     * with (0,0) being the top-left pixel in the active pixel array, and
     * ({@link CameraCharacteristics#SENSOR_INFO_ACTIVE_ARRAY_SIZE android.sensor.info.activeArraySize}.width - 1,
     * {@link CameraCharacteristics#SENSOR_INFO_ACTIVE_ARRAY_SIZE android.sensor.info.activeArraySize}.height - 1) being the
     * bottom-right pixel in the active pixel array.</p>
     * <p>The weight must be within <code>[0, 1000]</code>, and represents a weight
     * for every pixel in the area. This means that a large metering area
     * with the same weight as a smaller area will have more effect in
     * the metering result. Metering areas can partially overlap and the
     * camera device will add the weights in the overlap region.</p>
     * <p>The weights are relative to weights of other exposure metering regions, so if only one
     * region is used, all non-zero weights will have the same effect. A region with 0
     * weight is ignored.</p>
     * <p>If all regions have 0 weight, then no specific metering area needs to be used by the
     * camera device.</p>
     * <p>If the metering region is outside the used {@link CaptureRequest#SCALER_CROP_REGION android.scaler.cropRegion} returned in
     * capture result metadata, the camera device will ignore the sections outside the crop
     * region and output only the intersection rectangle as the metering region in the result
     * metadata.  If the region is entirely outside the crop region, it will be ignored and
     * not reported in the result metadata.</p>
     * <p><b>Units</b>: Pixel coordinates within {@link CameraCharacteristics#SENSOR_INFO_ACTIVE_ARRAY_SIZE android.sensor.info.activeArraySize}</p>
     * <p><b>Range of valid values:</b><br>
     * Coordinates must be between <code>[(0,0), (width, height))</code> of
     * {@link CameraCharacteristics#SENSOR_INFO_ACTIVE_ARRAY_SIZE android.sensor.info.activeArraySize}</p>
     * <p><b>Optional</b> - This value may be {@code null} on some devices.</p>
     *
     * @see CameraCharacteristics#CONTROL_MAX_REGIONS_AE
     * @see CaptureRequest#SCALER_CROP_REGION
     * @see CameraCharacteristics#SENSOR_INFO_ACTIVE_ARRAY_SIZE
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> CONTROL_AE_REGIONS;

    /**
     * <p>Range over which the auto-exposure routine can
     * adjust the capture frame rate to maintain good
     * exposure.</p>
     * <p>Only constrains auto-exposure (AE) algorithm, not
     * manual control of {@link CaptureRequest#SENSOR_EXPOSURE_TIME android.sensor.exposureTime} and
     * {@link CaptureRequest#SENSOR_FRAME_DURATION android.sensor.frameDuration}.</p>
     * <p><b>Units</b>: Frames per second (FPS)</p>
     * <p><b>Range of valid values:</b><br>
     * Any of the entries in {@link CameraCharacteristics#CONTROL_AE_AVAILABLE_TARGET_FPS_RANGES android.control.aeAvailableTargetFpsRanges}</p>
     * <p>This key is available on all devices.</p>
     *
     * @see CameraCharacteristics#CONTROL_AE_AVAILABLE_TARGET_FPS_RANGES
     * @see CaptureRequest#SENSOR_EXPOSURE_TIME
     * @see CaptureRequest#SENSOR_FRAME_DURATION
     */
    //@PublicKey
    //static const AutoPtr<ICaptureRequestKey> CONTROL_AE_TARGET_FPS_RANGE;

    /**
     * <p>Whether the camera device will trigger a precapture
     * metering sequence when it processes this request.</p>
     * <p>This entry is normally set to IDLE, or is not
     * included at all in the request settings. When included and
     * set to START, the camera device will trigger the autoexposure
     * precapture metering sequence.</p>
     * <p>The precapture sequence should triggered before starting a
     * high-quality still capture for final metering decisions to
     * be made, and for firing pre-capture flash pulses to estimate
     * scene brightness and required final capture flash power, when
     * the flash is enabled.</p>
     * <p>Normally, this entry should be set to START for only a
     * single request, and the application should wait until the
     * sequence completes before starting a new one.</p>
     * <p>The exact effect of auto-exposure (AE) precapture trigger
     * depends on the current AE mode and state; see
     * {@link CaptureResult#CONTROL_AE_STATE android.control.aeState} for AE precapture state transition
     * details.</p>
     * <p>On LEGACY-level devices, the precapture trigger is not supported;
     * capturing a high-resolution JPEG image will automatically trigger a
     * precapture sequence before the high-resolution capture, including
     * potentially firing a pre-capture flash.</p>
     * <p><b>Possible values:</b>
     * <ul>
     *   <li>{@link #CONTROL_AE_PRECAPTURE_TRIGGER_IDLE IDLE}</li>
     *   <li>{@link #CONTROL_AE_PRECAPTURE_TRIGGER_START START}</li>
     * </ul></p>
     * <p><b>Optional</b> - This value may be {@code null} on some devices.</p>
     * <p><b>Limited capability</b> -
     * Present on all camera devices that report being at least {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL_LIMITED HARDWARE_LEVEL_LIMITED} devices in the
     * {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL android.info.supportedHardwareLevel} key</p>
     *
     * @see CaptureResult#CONTROL_AE_STATE
     * @see CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL
     * @see #CONTROL_AE_PRECAPTURE_TRIGGER_IDLE
     * @see #CONTROL_AE_PRECAPTURE_TRIGGER_START
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> CONTROL_AE_PRECAPTURE_TRIGGER;

    /**
     * <p>Whether auto-focus (AF) is currently enabled, and what
     * mode it is set to.</p>
     * <p>Only effective if {@link CaptureRequest#CONTROL_MODE android.control.mode} = AUTO and the lens is not fixed focus
     * (i.e. <code>{@link CameraCharacteristics#LENS_INFO_MINIMUM_FOCUS_DISTANCE android.lens.info.minimumFocusDistance} &gt; 0</code>).</p>
     * <p>If the lens is controlled by the camera device auto-focus algorithm,
     * the camera device will report the current AF status in {@link CaptureResult#CONTROL_AF_STATE android.control.afState}
     * in result metadata.</p>
     * <p><b>Possible values:</b>
     * <ul>
     *   <li>{@link #CONTROL_AF_MODE_OFF OFF}</li>
     *   <li>{@link #CONTROL_AF_MODE_AUTO AUTO}</li>
     *   <li>{@link #CONTROL_AF_MODE_MACRO MACRO}</li>
     *   <li>{@link #CONTROL_AF_MODE_CONTINUOUS_VIDEO CONTINUOUS_VIDEO}</li>
     *   <li>{@link #CONTROL_AF_MODE_CONTINUOUS_PICTURE CONTINUOUS_PICTURE}</li>
     *   <li>{@link #CONTROL_AF_MODE_EDOF EDOF}</li>
     * </ul></p>
     * <p><b>Available values for this device:</b><br>
     * {@link CameraCharacteristics#CONTROL_AF_AVAILABLE_MODES android.control.afAvailableModes}</p>
     * <p>This key is available on all devices.</p>
     *
     * @see CameraCharacteristics#CONTROL_AF_AVAILABLE_MODES
     * @see CaptureResult#CONTROL_AF_STATE
     * @see CaptureRequest#CONTROL_MODE
     * @see CameraCharacteristics#LENS_INFO_MINIMUM_FOCUS_DISTANCE
     * @see #CONTROL_AF_MODE_OFF
     * @see #CONTROL_AF_MODE_AUTO
     * @see #CONTROL_AF_MODE_MACRO
     * @see #CONTROL_AF_MODE_CONTINUOUS_VIDEO
     * @see #CONTROL_AF_MODE_CONTINUOUS_PICTURE
     * @see #CONTROL_AF_MODE_EDOF
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> CONTROL_AF_MODE;

    /**
     * <p>List of metering areas to use for auto-focus.</p>
     * <p>Not available if {@link CameraCharacteristics#CONTROL_MAX_REGIONS_AF android.control.maxRegionsAf} is 0.
     * Otherwise will always be present.</p>
     * <p>The maximum number of focus areas supported by the device is determined by the value
     * of {@link CameraCharacteristics#CONTROL_MAX_REGIONS_AF android.control.maxRegionsAf}.</p>
     * <p>The coordinate system is based on the active pixel array,
     * with (0,0) being the top-left pixel in the active pixel array, and
     * ({@link CameraCharacteristics#SENSOR_INFO_ACTIVE_ARRAY_SIZE android.sensor.info.activeArraySize}.width - 1,
     * {@link CameraCharacteristics#SENSOR_INFO_ACTIVE_ARRAY_SIZE android.sensor.info.activeArraySize}.height - 1) being the
     * bottom-right pixel in the active pixel array.</p>
     * <p>The weight must be within <code>[0, 1000]</code>, and represents a weight
     * for every pixel in the area. This means that a large metering area
     * with the same weight as a smaller area will have more effect in
     * the metering result. Metering areas can partially overlap and the
     * camera device will add the weights in the overlap region.</p>
     * <p>The weights are relative to weights of other metering regions, so if only one region
     * is used, all non-zero weights will have the same effect. A region with 0 weight is
     * ignored.</p>
     * <p>If all regions have 0 weight, then no specific metering area needs to be used by the
     * camera device.</p>
     * <p>If the metering region is outside the used {@link CaptureRequest#SCALER_CROP_REGION android.scaler.cropRegion} returned in
     * capture result metadata, the camera device will ignore the sections outside the crop
     * region and output only the intersection rectangle as the metering region in the result
     * metadata. If the region is entirely outside the crop region, it will be ignored and
     * not reported in the result metadata.</p>
     * <p><b>Units</b>: Pixel coordinates within {@link CameraCharacteristics#SENSOR_INFO_ACTIVE_ARRAY_SIZE android.sensor.info.activeArraySize}</p>
     * <p><b>Range of valid values:</b><br>
     * Coordinates must be between <code>[(0,0), (width, height))</code> of
     * {@link CameraCharacteristics#SENSOR_INFO_ACTIVE_ARRAY_SIZE android.sensor.info.activeArraySize}</p>
     * <p><b>Optional</b> - This value may be {@code null} on some devices.</p>
     *
     * @see CameraCharacteristics#CONTROL_MAX_REGIONS_AF
     * @see CaptureRequest#SCALER_CROP_REGION
     * @see CameraCharacteristics#SENSOR_INFO_ACTIVE_ARRAY_SIZE
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> CONTROL_AF_REGIONS;

    /**
     * <p>Whether the camera device will trigger autofocus for this request.</p>
     * <p>This entry is normally set to IDLE, or is not
     * included at all in the request settings.</p>
     * <p>When included and set to START, the camera device will trigger the
     * autofocus algorithm. If autofocus is disabled, this trigger has no effect.</p>
     * <p>When set to CANCEL, the camera device will cancel any active trigger,
     * and return to its initial AF state.</p>
     * <p>Generally, applications should set this entry to START or CANCEL for only a
     * single capture, and then return it to IDLE (or not set at all). Specifying
     * START for multiple captures in a row means restarting the AF operation over
     * and over again.</p>
     * <p>See {@link CaptureResult#CONTROL_AF_STATE android.control.afState} for what the trigger means for each AF mode.</p>
     * <p><b>Possible values:</b>
     * <ul>
     *   <li>{@link #CONTROL_AF_TRIGGER_IDLE IDLE}</li>
     *   <li>{@link #CONTROL_AF_TRIGGER_START START}</li>
     *   <li>{@link #CONTROL_AF_TRIGGER_CANCEL CANCEL}</li>
     * </ul></p>
     * <p>This key is available on all devices.</p>
     *
     * @see CaptureResult#CONTROL_AF_STATE
     * @see #CONTROL_AF_TRIGGER_IDLE
     * @see #CONTROL_AF_TRIGGER_START
     * @see #CONTROL_AF_TRIGGER_CANCEL
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> CONTROL_AF_TRIGGER;

    /**
     * <p>Whether auto-white balance (AWB) is currently locked to its
     * latest calculated values.</p>
     * <p>When set to <code>true</code> (ON), the AWB algorithm is locked to its latest parameters,
     * and will not change color balance settings until the lock is set to <code>false</code> (OFF).</p>
     * <p>Since the camera device has a pipeline of in-flight requests, the settings that
     * get locked do not necessarily correspond to the settings that were present in the
     * latest capture result received from the camera device, since additional captures
     * and AWB updates may have occurred even before the result was sent out. If an
     * application is switching between automatic and manual control and wishes to eliminate
     * any flicker during the switch, the following procedure is recommended:</p>
     * <ol>
     * <li>Starting in auto-AWB mode:</li>
     * <li>Lock AWB</li>
     * <li>Wait for the first result to be output that has the AWB locked</li>
     * <li>Copy AWB settings from that result into a request, set the request to manual AWB</li>
     * <li>Submit the capture request, proceed to run manual AWB as desired.</li>
     * </ol>
     * <p>Note that AWB lock is only meaningful when
     * {@link CaptureRequest#CONTROL_AWB_MODE android.control.awbMode} is in the AUTO mode; in other modes,
     * AWB is already fixed to a specific setting.</p>
     * <p>Some LEGACY devices may not support ON; the value is then overridden to OFF.</p>
     * <p>This key is available on all devices.</p>
     *
     * @see CaptureRequest#CONTROL_AWB_MODE
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> CONTROL_AWB_LOCK;

    /**
     * <p>Whether auto-white balance (AWB) is currently setting the color
     * transform fields, and what its illumination target
     * is.</p>
     * <p>This control is only effective if {@link CaptureRequest#CONTROL_MODE android.control.mode} is AUTO.</p>
     * <p>When set to the ON mode, the camera device's auto-white balance
     * routine is enabled, overriding the application's selected
     * {@link CaptureRequest#COLOR_CORRECTION_TRANSFORM android.colorCorrection.transform}, {@link CaptureRequest#COLOR_CORRECTION_GAINS android.colorCorrection.gains} and
     * {@link CaptureRequest#COLOR_CORRECTION_MODE android.colorCorrection.mode}.</p>
     * <p>When set to the OFF mode, the camera device's auto-white balance
     * routine is disabled. The application manually controls the white
     * balance by {@link CaptureRequest#COLOR_CORRECTION_TRANSFORM android.colorCorrection.transform}, {@link CaptureRequest#COLOR_CORRECTION_GAINS android.colorCorrection.gains}
     * and {@link CaptureRequest#COLOR_CORRECTION_MODE android.colorCorrection.mode}.</p>
     * <p>When set to any other modes, the camera device's auto-white
     * balance routine is disabled. The camera device uses each
     * particular illumination target for white balance
     * adjustment. The application's values for
     * {@link CaptureRequest#COLOR_CORRECTION_TRANSFORM android.colorCorrection.transform},
     * {@link CaptureRequest#COLOR_CORRECTION_GAINS android.colorCorrection.gains} and
     * {@link CaptureRequest#COLOR_CORRECTION_MODE android.colorCorrection.mode} are ignored.</p>
     * <p><b>Possible values:</b>
     * <ul>
     *   <li>{@link #CONTROL_AWB_MODE_OFF OFF}</li>
     *   <li>{@link #CONTROL_AWB_MODE_AUTO AUTO}</li>
     *   <li>{@link #CONTROL_AWB_MODE_INCANDESCENT INCANDESCENT}</li>
     *   <li>{@link #CONTROL_AWB_MODE_FLUORESCENT FLUORESCENT}</li>
     *   <li>{@link #CONTROL_AWB_MODE_WARM_FLUORESCENT WARM_FLUORESCENT}</li>
     *   <li>{@link #CONTROL_AWB_MODE_DAYLIGHT DAYLIGHT}</li>
     *   <li>{@link #CONTROL_AWB_MODE_CLOUDY_DAYLIGHT CLOUDY_DAYLIGHT}</li>
     *   <li>{@link #CONTROL_AWB_MODE_TWILIGHT TWILIGHT}</li>
     *   <li>{@link #CONTROL_AWB_MODE_SHADE SHADE}</li>
     * </ul></p>
     * <p><b>Available values for this device:</b><br>
     * {@link CameraCharacteristics#CONTROL_AWB_AVAILABLE_MODES android.control.awbAvailableModes}</p>
     * <p>This key is available on all devices.</p>
     *
     * @see CaptureRequest#COLOR_CORRECTION_GAINS
     * @see CaptureRequest#COLOR_CORRECTION_MODE
     * @see CaptureRequest#COLOR_CORRECTION_TRANSFORM
     * @see CameraCharacteristics#CONTROL_AWB_AVAILABLE_MODES
     * @see CaptureRequest#CONTROL_MODE
     * @see #CONTROL_AWB_MODE_OFF
     * @see #CONTROL_AWB_MODE_AUTO
     * @see #CONTROL_AWB_MODE_INCANDESCENT
     * @see #CONTROL_AWB_MODE_FLUORESCENT
     * @see #CONTROL_AWB_MODE_WARM_FLUORESCENT
     * @see #CONTROL_AWB_MODE_DAYLIGHT
     * @see #CONTROL_AWB_MODE_CLOUDY_DAYLIGHT
     * @see #CONTROL_AWB_MODE_TWILIGHT
     * @see #CONTROL_AWB_MODE_SHADE
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> CONTROL_AWB_MODE;

    /**
     * <p>List of metering areas to use for auto-white-balance illuminant
     * estimation.</p>
     * <p>Not available if {@link CameraCharacteristics#CONTROL_MAX_REGIONS_AWB android.control.maxRegionsAwb} is 0.
     * Otherwise will always be present.</p>
     * <p>The maximum number of regions supported by the device is determined by the value
     * of {@link CameraCharacteristics#CONTROL_MAX_REGIONS_AWB android.control.maxRegionsAwb}.</p>
     * <p>The coordinate system is based on the active pixel array,
     * with (0,0) being the top-left pixel in the active pixel array, and
     * ({@link CameraCharacteristics#SENSOR_INFO_ACTIVE_ARRAY_SIZE android.sensor.info.activeArraySize}.width - 1,
     * {@link CameraCharacteristics#SENSOR_INFO_ACTIVE_ARRAY_SIZE android.sensor.info.activeArraySize}.height - 1) being the
     * bottom-right pixel in the active pixel array.</p>
     * <p>The weight must range from 0 to 1000, and represents a weight
     * for every pixel in the area. This means that a large metering area
     * with the same weight as a smaller area will have more effect in
     * the metering result. Metering areas can partially overlap and the
     * camera device will add the weights in the overlap region.</p>
     * <p>The weights are relative to weights of other white balance metering regions, so if
     * only one region is used, all non-zero weights will have the same effect. A region with
     * 0 weight is ignored.</p>
     * <p>If all regions have 0 weight, then no specific metering area needs to be used by the
     * camera device.</p>
     * <p>If the metering region is outside the used {@link CaptureRequest#SCALER_CROP_REGION android.scaler.cropRegion} returned in
     * capture result metadata, the camera device will ignore the sections outside the crop
     * region and output only the intersection rectangle as the metering region in the result
     * metadata.  If the region is entirely outside the crop region, it will be ignored and
     * not reported in the result metadata.</p>
     * <p><b>Units</b>: Pixel coordinates within {@link CameraCharacteristics#SENSOR_INFO_ACTIVE_ARRAY_SIZE android.sensor.info.activeArraySize}</p>
     * <p><b>Range of valid values:</b><br>
     * Coordinates must be between <code>[(0,0), (width, height))</code> of
     * {@link CameraCharacteristics#SENSOR_INFO_ACTIVE_ARRAY_SIZE android.sensor.info.activeArraySize}</p>
     * <p><b>Optional</b> - This value may be {@code null} on some devices.</p>
     *
     * @see CameraCharacteristics#CONTROL_MAX_REGIONS_AWB
     * @see CaptureRequest#SCALER_CROP_REGION
     * @see CameraCharacteristics#SENSOR_INFO_ACTIVE_ARRAY_SIZE
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> CONTROL_AWB_REGIONS;

    /**
     * <p>Information to the camera device 3A (auto-exposure,
     * auto-focus, auto-white balance) routines about the purpose
     * of this capture, to help the camera device to decide optimal 3A
     * strategy.</p>
     * <p>This control (except for MANUAL) is only effective if
     * <code>{@link CaptureRequest#CONTROL_MODE android.control.mode} != OFF</code> and any 3A routine is active.</p>
     * <p>ZERO_SHUTTER_LAG will be supported if {@link CameraCharacteristics#REQUEST_AVAILABLE_CAPABILITIES android.request.availableCapabilities}
     * contains ZSL. MANUAL will be supported if {@link CameraCharacteristics#REQUEST_AVAILABLE_CAPABILITIES android.request.availableCapabilities}
     * contains MANUAL_SENSOR. Other intent values are always supported.</p>
     * <p><b>Possible values:</b>
     * <ul>
     *   <li>{@link #CONTROL_CAPTURE_INTENT_CUSTOM CUSTOM}</li>
     *   <li>{@link #CONTROL_CAPTURE_INTENT_PREVIEW PREVIEW}</li>
     *   <li>{@link #CONTROL_CAPTURE_INTENT_STILL_CAPTURE STILL_CAPTURE}</li>
     *   <li>{@link #CONTROL_CAPTURE_INTENT_VIDEO_RECORD VIDEO_RECORD}</li>
     *   <li>{@link #CONTROL_CAPTURE_INTENT_VIDEO_SNAPSHOT VIDEO_SNAPSHOT}</li>
     *   <li>{@link #CONTROL_CAPTURE_INTENT_ZERO_SHUTTER_LAG ZERO_SHUTTER_LAG}</li>
     *   <li>{@link #CONTROL_CAPTURE_INTENT_MANUAL MANUAL}</li>
     * </ul></p>
     * <p>This key is available on all devices.</p>
     *
     * @see CaptureRequest#CONTROL_MODE
     * @see CameraCharacteristics#REQUEST_AVAILABLE_CAPABILITIES
     * @see #CONTROL_CAPTURE_INTENT_CUSTOM
     * @see #CONTROL_CAPTURE_INTENT_PREVIEW
     * @see #CONTROL_CAPTURE_INTENT_STILL_CAPTURE
     * @see #CONTROL_CAPTURE_INTENT_VIDEO_RECORD
     * @see #CONTROL_CAPTURE_INTENT_VIDEO_SNAPSHOT
     * @see #CONTROL_CAPTURE_INTENT_ZERO_SHUTTER_LAG
     * @see #CONTROL_CAPTURE_INTENT_MANUAL
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> CONTROL_CAPTURE_INTENT;

    /**
     * <p>A special color effect to apply.</p>
     * <p>When this mode is set, a color effect will be applied
     * to images produced by the camera device. The interpretation
     * and implementation of these color effects is left to the
     * implementor of the camera device, and should not be
     * depended on to be consistent (or present) across all
     * devices.</p>
     * <p><b>Possible values:</b>
     * <ul>
     *   <li>{@link #CONTROL_EFFECT_MODE_OFF OFF}</li>
     *   <li>{@link #CONTROL_EFFECT_MODE_MONO MONO}</li>
     *   <li>{@link #CONTROL_EFFECT_MODE_NEGATIVE NEGATIVE}</li>
     *   <li>{@link #CONTROL_EFFECT_MODE_SOLARIZE SOLARIZE}</li>
     *   <li>{@link #CONTROL_EFFECT_MODE_SEPIA SEPIA}</li>
     *   <li>{@link #CONTROL_EFFECT_MODE_POSTERIZE POSTERIZE}</li>
     *   <li>{@link #CONTROL_EFFECT_MODE_WHITEBOARD WHITEBOARD}</li>
     *   <li>{@link #CONTROL_EFFECT_MODE_BLACKBOARD BLACKBOARD}</li>
     *   <li>{@link #CONTROL_EFFECT_MODE_AQUA AQUA}</li>
     * </ul></p>
     * <p><b>Available values for this device:</b><br>
     * {@link CameraCharacteristics#CONTROL_AVAILABLE_EFFECTS android.control.availableEffects}</p>
     * <p>This key is available on all devices.</p>
     *
     * @see CameraCharacteristics#CONTROL_AVAILABLE_EFFECTS
     * @see #CONTROL_EFFECT_MODE_OFF
     * @see #CONTROL_EFFECT_MODE_MONO
     * @see #CONTROL_EFFECT_MODE_NEGATIVE
     * @see #CONTROL_EFFECT_MODE_SOLARIZE
     * @see #CONTROL_EFFECT_MODE_SEPIA
     * @see #CONTROL_EFFECT_MODE_POSTERIZE
     * @see #CONTROL_EFFECT_MODE_WHITEBOARD
     * @see #CONTROL_EFFECT_MODE_BLACKBOARD
     * @see #CONTROL_EFFECT_MODE_AQUA
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> CONTROL_EFFECT_MODE;

    /**
     * <p>Overall mode of 3A (auto-exposure, auto-white-balance, auto-focus) control
     * routines.</p>
     * <p>This is a top-level 3A control switch. When set to OFF, all 3A control
     * by the camera device is disabled. The application must set the fields for
     * capture parameters itself.</p>
     * <p>When set to AUTO, the individual algorithm controls in
     * android.control.* are in effect, such as {@link CaptureRequest#CONTROL_AF_MODE android.control.afMode}.</p>
     * <p>When set to USE_SCENE_MODE, the individual controls in
     * android.control.* are mostly disabled, and the camera device implements
     * one of the scene mode settings (such as ACTION, SUNSET, or PARTY)
     * as it wishes. The camera device scene mode 3A settings are provided by
     * android.control.sceneModeOverrides.</p>
     * <p>When set to OFF_KEEP_STATE, it is similar to OFF mode, the only difference
     * is that this frame will not be used by camera device background 3A statistics
     * update, as if this frame is never captured. This mode can be used in the scenario
     * where the application doesn't want a 3A manual control capture to affect
     * the subsequent auto 3A capture results.</p>
     * <p>LEGACY mode devices will only support AUTO and USE_SCENE_MODE modes.
     * LIMITED mode devices will only support OFF and OFF_KEEP_STATE if they
     * support the MANUAL_SENSOR and MANUAL_POST_PROCSESING capabilities.
     * FULL mode devices will always support OFF and OFF_KEEP_STATE.</p>
     * <p><b>Possible values:</b>
     * <ul>
     *   <li>{@link #CONTROL_MODE_OFF OFF}</li>
     *   <li>{@link #CONTROL_MODE_AUTO AUTO}</li>
     *   <li>{@link #CONTROL_MODE_USE_SCENE_MODE USE_SCENE_MODE}</li>
     *   <li>{@link #CONTROL_MODE_OFF_KEEP_STATE OFF_KEEP_STATE}</li>
     * </ul></p>
     * <p>This key is available on all devices.</p>
     *
     * @see CaptureRequest#CONTROL_AF_MODE
     * @see #CONTROL_MODE_OFF
     * @see #CONTROL_MODE_AUTO
     * @see #CONTROL_MODE_USE_SCENE_MODE
     * @see #CONTROL_MODE_OFF_KEEP_STATE
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> CONTROL_MODE;

    /**
     * <p>Control for which scene mode is currently active.</p>
     * <p>Scene modes are custom camera modes optimized for a certain set of conditions and
     * capture settings.</p>
     * <p>This is the mode that that is active when
     * <code>{@link CaptureRequest#CONTROL_MODE android.control.mode} == USE_SCENE_MODE</code>. Aside from FACE_PRIORITY,
     * these modes will disable {@link CaptureRequest#CONTROL_AE_MODE android.control.aeMode},
     * {@link CaptureRequest#CONTROL_AWB_MODE android.control.awbMode}, and {@link CaptureRequest#CONTROL_AF_MODE android.control.afMode} while in use.</p>
     * <p>The interpretation and implementation of these scene modes is left
     * to the implementor of the camera device. Their behavior will not be
     * consistent across all devices, and any given device may only implement
     * a subset of these modes.</p>
     * <p><b>Possible values:</b>
     * <ul>
     *   <li>{@link #CONTROL_SCENE_MODE_DISABLED DISABLED}</li>
     *   <li>{@link #CONTROL_SCENE_MODE_FACE_PRIORITY FACE_PRIORITY}</li>
     *   <li>{@link #CONTROL_SCENE_MODE_ACTION ACTION}</li>
     *   <li>{@link #CONTROL_SCENE_MODE_PORTRAIT PORTRAIT}</li>
     *   <li>{@link #CONTROL_SCENE_MODE_LANDSCAPE LANDSCAPE}</li>
     *   <li>{@link #CONTROL_SCENE_MODE_NIGHT NIGHT}</li>
     *   <li>{@link #CONTROL_SCENE_MODE_NIGHT_PORTRAIT NIGHT_PORTRAIT}</li>
     *   <li>{@link #CONTROL_SCENE_MODE_THEATRE THEATRE}</li>
     *   <li>{@link #CONTROL_SCENE_MODE_BEACH BEACH}</li>
     *   <li>{@link #CONTROL_SCENE_MODE_SNOW SNOW}</li>
     *   <li>{@link #CONTROL_SCENE_MODE_SUNSET SUNSET}</li>
     *   <li>{@link #CONTROL_SCENE_MODE_STEADYPHOTO STEADYPHOTO}</li>
     *   <li>{@link #CONTROL_SCENE_MODE_FIREWORKS FIREWORKS}</li>
     *   <li>{@link #CONTROL_SCENE_MODE_SPORTS SPORTS}</li>
     *   <li>{@link #CONTROL_SCENE_MODE_PARTY PARTY}</li>
     *   <li>{@link #CONTROL_SCENE_MODE_CANDLELIGHT CANDLELIGHT}</li>
     *   <li>{@link #CONTROL_SCENE_MODE_BARCODE BARCODE}</li>
     *   <li>{@link #CONTROL_SCENE_MODE_HIGH_SPEED_VIDEO HIGH_SPEED_VIDEO}</li>
     * </ul></p>
     * <p><b>Available values for this device:</b><br>
     * {@link CameraCharacteristics#CONTROL_AVAILABLE_SCENE_MODES android.control.availableSceneModes}</p>
     * <p>This key is available on all devices.</p>
     *
     * @see CaptureRequest#CONTROL_AE_MODE
     * @see CaptureRequest#CONTROL_AF_MODE
     * @see CameraCharacteristics#CONTROL_AVAILABLE_SCENE_MODES
     * @see CaptureRequest#CONTROL_AWB_MODE
     * @see CaptureRequest#CONTROL_MODE
     * @see #CONTROL_SCENE_MODE_DISABLED
     * @see #CONTROL_SCENE_MODE_FACE_PRIORITY
     * @see #CONTROL_SCENE_MODE_ACTION
     * @see #CONTROL_SCENE_MODE_PORTRAIT
     * @see #CONTROL_SCENE_MODE_LANDSCAPE
     * @see #CONTROL_SCENE_MODE_NIGHT
     * @see #CONTROL_SCENE_MODE_NIGHT_PORTRAIT
     * @see #CONTROL_SCENE_MODE_THEATRE
     * @see #CONTROL_SCENE_MODE_BEACH
     * @see #CONTROL_SCENE_MODE_SNOW
     * @see #CONTROL_SCENE_MODE_SUNSET
     * @see #CONTROL_SCENE_MODE_STEADYPHOTO
     * @see #CONTROL_SCENE_MODE_FIREWORKS
     * @see #CONTROL_SCENE_MODE_SPORTS
     * @see #CONTROL_SCENE_MODE_PARTY
     * @see #CONTROL_SCENE_MODE_CANDLELIGHT
     * @see #CONTROL_SCENE_MODE_BARCODE
     * @see #CONTROL_SCENE_MODE_HIGH_SPEED_VIDEO
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> CONTROL_SCENE_MODE;

    /**
     * <p>Whether video stabilization is
     * active.</p>
     * <p>Video stabilization automatically translates and scales images from
     * the camera in order to stabilize motion between consecutive frames.</p>
     * <p>If enabled, video stabilization can modify the
     * {@link CaptureRequest#SCALER_CROP_REGION android.scaler.cropRegion} to keep the video stream stabilized.</p>
     * <p>Switching between different video stabilization modes may take several
     * frames to initialize, the camera device will report the current mode
     * in capture result metadata. For example, When "ON" mode is requested,
     * the video stabilization modes in the first several capture results may
     * still be "OFF", and it will become "ON" when the initialization is
     * done.</p>
     * <p>If a camera device supports both this mode and OIS
     * ({@link CaptureRequest#LENS_OPTICAL_STABILIZATION_MODE android.lens.opticalStabilizationMode}), turning both modes on may
     * produce undesirable interaction, so it is recommended not to enable
     * both at the same time.</p>
     * <p><b>Possible values:</b>
     * <ul>
     *   <li>{@link #CONTROL_VIDEO_STABILIZATION_MODE_OFF OFF}</li>
     *   <li>{@link #CONTROL_VIDEO_STABILIZATION_MODE_ON ON}</li>
     * </ul></p>
     * <p>This key is available on all devices.</p>
     *
     * @see CaptureRequest#LENS_OPTICAL_STABILIZATION_MODE
     * @see CaptureRequest#SCALER_CROP_REGION
     * @see #CONTROL_VIDEO_STABILIZATION_MODE_OFF
     * @see #CONTROL_VIDEO_STABILIZATION_MODE_ON
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> CONTROL_VIDEO_STABILIZATION_MODE;

    /**
     * <p>Operation mode for edge
     * enhancement.</p>
     * <p>Edge enhancement improves sharpness and details in the captured image. OFF means
     * no enhancement will be applied by the camera device.</p>
     * <p>FAST/HIGH_QUALITY both mean camera device determined enhancement
     * will be applied. HIGH_QUALITY mode indicates that the
     * camera device will use the highest-quality enhancement algorithms,
     * even if it slows down capture rate. FAST means the camera device will
     * not slow down capture rate when applying edge enhancement.</p>
     * <p><b>Possible values:</b>
     * <ul>
     *   <li>{@link #EDGE_MODE_OFF OFF}</li>
     *   <li>{@link #EDGE_MODE_FAST FAST}</li>
     *   <li>{@link #EDGE_MODE_HIGH_QUALITY HIGH_QUALITY}</li>
     * </ul></p>
     * <p><b>Available values for this device:</b><br>
     * {@link CameraCharacteristics#EDGE_AVAILABLE_EDGE_MODES android.edge.availableEdgeModes}</p>
     * <p><b>Optional</b> - This value may be {@code null} on some devices.</p>
     * <p><b>Full capability</b> -
     * Present on all camera devices that report being {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL_FULL HARDWARE_LEVEL_FULL} devices in the
     * {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL android.info.supportedHardwareLevel} key</p>
     *
     * @see CameraCharacteristics#EDGE_AVAILABLE_EDGE_MODES
     * @see CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL
     * @see #EDGE_MODE_OFF
     * @see #EDGE_MODE_FAST
     * @see #EDGE_MODE_HIGH_QUALITY
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> EDGE_MODE;

    /**
     * <p>The desired mode for for the camera device's flash control.</p>
     * <p>This control is only effective when flash unit is available
     * (<code>{@link CameraCharacteristics#FLASH_INFO_AVAILABLE android.flash.info.available} == true</code>).</p>
     * <p>When this control is used, the {@link CaptureRequest#CONTROL_AE_MODE android.control.aeMode} must be set to ON or OFF.
     * Otherwise, the camera device auto-exposure related flash control (ON_AUTO_FLASH,
     * ON_ALWAYS_FLASH, or ON_AUTO_FLASH_REDEYE) will override this control.</p>
     * <p>When set to OFF, the camera device will not fire flash for this capture.</p>
     * <p>When set to SINGLE, the camera device will fire flash regardless of the camera
     * device's auto-exposure routine's result. When used in still capture case, this
     * control should be used along with auto-exposure (AE) precapture metering sequence
     * ({@link CaptureRequest#CONTROL_AE_PRECAPTURE_TRIGGER android.control.aePrecaptureTrigger}), otherwise, the image may be incorrectly exposed.</p>
     * <p>When set to TORCH, the flash will be on continuously. This mode can be used
     * for use cases such as preview, auto-focus assist, still capture, or video recording.</p>
     * <p>The flash status will be reported by {@link CaptureResult#FLASH_STATE android.flash.state} in the capture result metadata.</p>
     * <p><b>Possible values:</b>
     * <ul>
     *   <li>{@link #FLASH_MODE_OFF OFF}</li>
     *   <li>{@link #FLASH_MODE_SINGLE SINGLE}</li>
     *   <li>{@link #FLASH_MODE_TORCH TORCH}</li>
     * </ul></p>
     * <p>This key is available on all devices.</p>
     *
     * @see CaptureRequest#CONTROL_AE_MODE
     * @see CaptureRequest#CONTROL_AE_PRECAPTURE_TRIGGER
     * @see CameraCharacteristics#FLASH_INFO_AVAILABLE
     * @see CaptureResult#FLASH_STATE
     * @see #FLASH_MODE_OFF
     * @see #FLASH_MODE_SINGLE
     * @see #FLASH_MODE_TORCH
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> FLASH_MODE;

    /**
     * <p>Operational mode for hot pixel correction.</p>
     * <p>Hotpixel correction interpolates out, or otherwise removes, pixels
     * that do not accurately measure the incoming light (i.e. pixels that
     * are stuck at an arbitrary value or are oversensitive).</p>
     * <p><b>Possible values:</b>
     * <ul>
     *   <li>{@link #HOT_PIXEL_MODE_OFF OFF}</li>
     *   <li>{@link #HOT_PIXEL_MODE_FAST FAST}</li>
     *   <li>{@link #HOT_PIXEL_MODE_HIGH_QUALITY HIGH_QUALITY}</li>
     * </ul></p>
     * <p><b>Available values for this device:</b><br>
     * {@link CameraCharacteristics#HOT_PIXEL_AVAILABLE_HOT_PIXEL_MODES android.hotPixel.availableHotPixelModes}</p>
     * <p><b>Optional</b> - This value may be {@code null} on some devices.</p>
     *
     * @see CameraCharacteristics#HOT_PIXEL_AVAILABLE_HOT_PIXEL_MODES
     * @see #HOT_PIXEL_MODE_OFF
     * @see #HOT_PIXEL_MODE_FAST
     * @see #HOT_PIXEL_MODE_HIGH_QUALITY
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> HOT_PIXEL_MODE;

    /**
     * <p>A location object to use when generating image GPS metadata.</p>
     * <p>Setting a location object in a request will include the GPS coordinates of the location
     * into any JPEG images captured based on the request. These coordinates can then be
     * viewed by anyone who receives the JPEG image.</p>
     * <p>This key is available on all devices.</p>
     */
    //@PublicKey
    //@SyntheticKey
    static const AutoPtr<ICaptureRequestKey> JPEG_GPS_LOCATION;

    /**
     * <p>GPS coordinates to include in output JPEG
     * EXIF.</p>
     * <p><b>Range of valid values:</b><br>
     * (-180 - 180], [-90,90], [-inf, inf]</p>
     * <p>This key is available on all devices.</p>
     * @hide
     */
    static const AutoPtr<ICaptureRequestKey> JPEG_GPS_COORDINATES;

    /**
     * <p>32 characters describing GPS algorithm to
     * include in EXIF.</p>
     * <p><b>Units</b>: UTF-8 null-terminated string</p>
     * <p>This key is available on all devices.</p>
     * @hide
     */
    static const AutoPtr<ICaptureRequestKey> JPEG_GPS_PROCESSING_METHOD;

    /**
     * <p>Time GPS fix was made to include in
     * EXIF.</p>
     * <p><b>Units</b>: UTC in seconds since January 1, 1970</p>
     * <p>This key is available on all devices.</p>
     * @hide
     */
    static const AutoPtr<ICaptureRequestKey> JPEG_GPS_TIMESTAMP;

    /**
     * <p>The orientation for a JPEG image.</p>
     * <p>The clockwise rotation angle in degrees, relative to the orientation
     * to the camera, that the JPEG picture needs to be rotated by, to be viewed
     * upright.</p>
     * <p>Camera devices may either encode this value into the JPEG EXIF header, or
     * rotate the image data to match this orientation.</p>
     * <p>Note that this orientation is relative to the orientation of the camera sensor, given
     * by {@link CameraCharacteristics#SENSOR_ORIENTATION android.sensor.orientation}.</p>
     * <p>To translate from the device orientation given by the Android sensor APIs, the following
     * sample code may be used:</p>
     * <pre><code>private int getJpegOrientation(CameraCharacteristics c, int deviceOrientation) {
     *     if (deviceOrientation == android.view.OrientationEventListener.ORIENTATION_UNKNOWN) return 0;
     *     int sensorOrientation = c.get(CameraCharacteristics.SENSOR_ORIENTATION);
     *
     *     // Round device orientation to a multiple of 90
     *     deviceOrientation = (deviceOrientation + 45) / 90 * 90;
     *
     *     // Reverse device orientation for front-facing cameras
     *     boolean facingFront = c.get(CameraCharacteristics.LENS_FACING) == CameraCharacteristics.LENS_FACING_FRONT;
     *     if (facingFront) deviceOrientation = -deviceOrientation;
     *
     *     // Calculate desired JPEG orientation relative to camera orientation to make
     *     // the image upright relative to the device orientation
     *     int jpegOrientation = (sensorOrientation + deviceOrientation + 360) % 360;
     *
     *     return jpegOrientation;
     * }
     * </code></pre>
     * <p><b>Units</b>: Degrees in multiples of 90</p>
     * <p><b>Range of valid values:</b><br>
     * 0, 90, 180, 270</p>
     * <p>This key is available on all devices.</p>
     *
     * @see CameraCharacteristics#SENSOR_ORIENTATION
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> JPEG_ORIENTATION;

    /**
     * <p>Compression quality of the final JPEG
     * image.</p>
     * <p>85-95 is typical usage range.</p>
     * <p><b>Range of valid values:</b><br>
     * 1-100; larger is higher quality</p>
     * <p>This key is available on all devices.</p>
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> JPEG_QUALITY;

    /**
     * <p>Compression quality of JPEG
     * thumbnail.</p>
     * <p><b>Range of valid values:</b><br>
     * 1-100; larger is higher quality</p>
     * <p>This key is available on all devices.</p>
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> JPEG_THUMBNAIL_QUALITY;

    /**
     * <p>Resolution of embedded JPEG thumbnail.</p>
     * <p>When set to (0, 0) value, the JPEG EXIF will not contain thumbnail,
     * but the captured JPEG will still be a valid image.</p>
     * <p>For best results, when issuing a request for a JPEG image, the thumbnail size selected
     * should have the same aspect ratio as the main JPEG output.</p>
     * <p>If the thumbnail image aspect ratio differs from the JPEG primary image aspect
     * ratio, the camera device creates the thumbnail by cropping it from the primary image.
     * For example, if the primary image has 4:3 aspect ratio, the thumbnail image has
     * 16:9 aspect ratio, the primary image will be cropped vertically (letterbox) to
     * generate the thumbnail image. The thumbnail image will always have a smaller Field
     * Of View (FOV) than the primary image when aspect ratios differ.</p>
     * <p><b>Range of valid values:</b><br>
     * {@link CameraCharacteristics#JPEG_AVAILABLE_THUMBNAIL_SIZES android.jpeg.availableThumbnailSizes}</p>
     * <p>This key is available on all devices.</p>
     *
     * @see CameraCharacteristics#JPEG_AVAILABLE_THUMBNAIL_SIZES
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> JPEG_THUMBNAIL_SIZE;

    /**
     * <p>The desired lens aperture size, as a ratio of lens focal length to the
     * effective aperture diameter.</p>
     * <p>Setting this value is only supported on the camera devices that have a variable
     * aperture lens.</p>
     * <p>When this is supported and {@link CaptureRequest#CONTROL_AE_MODE android.control.aeMode} is OFF,
     * this can be set along with {@link CaptureRequest#SENSOR_EXPOSURE_TIME android.sensor.exposureTime},
     * {@link CaptureRequest#SENSOR_SENSITIVITY android.sensor.sensitivity}, and {@link CaptureRequest#SENSOR_FRAME_DURATION android.sensor.frameDuration}
     * to achieve manual exposure control.</p>
     * <p>The requested aperture value may take several frames to reach the
     * requested value; the camera device will report the current (intermediate)
     * aperture size in capture result metadata while the aperture is changing.
     * While the aperture is still changing, {@link CaptureResult#LENS_STATE android.lens.state} will be set to MOVING.</p>
     * <p>When this is supported and {@link CaptureRequest#CONTROL_AE_MODE android.control.aeMode} is one of
     * the ON modes, this will be overridden by the camera device
     * auto-exposure algorithm, the overridden values are then provided
     * back to the user in the corresponding result.</p>
     * <p><b>Units</b>: The f-number (f/N)</p>
     * <p><b>Range of valid values:</b><br>
     * {@link CameraCharacteristics#LENS_INFO_AVAILABLE_APERTURES android.lens.info.availableApertures}</p>
     * <p><b>Optional</b> - This value may be {@code null} on some devices.</p>
     * <p><b>Full capability</b> -
     * Present on all camera devices that report being {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL_FULL HARDWARE_LEVEL_FULL} devices in the
     * {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL android.info.supportedHardwareLevel} key</p>
     *
     * @see CaptureRequest#CONTROL_AE_MODE
     * @see CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL
     * @see CameraCharacteristics#LENS_INFO_AVAILABLE_APERTURES
     * @see CaptureResult#LENS_STATE
     * @see CaptureRequest#SENSOR_EXPOSURE_TIME
     * @see CaptureRequest#SENSOR_FRAME_DURATION
     * @see CaptureRequest#SENSOR_SENSITIVITY
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> LENS_APERTURE;

    /**
     * <p>The desired setting for the lens neutral density filter(s).</p>
     * <p>This control will not be supported on most camera devices.</p>
     * <p>Lens filters are typically used to lower the amount of light the
     * sensor is exposed to (measured in steps of EV). As used here, an EV
     * step is the standard logarithmic representation, which are
     * non-negative, and inversely proportional to the amount of light
     * hitting the sensor.  For example, setting this to 0 would result
     * in no reduction of the incoming light, and setting this to 2 would
     * mean that the filter is set to reduce incoming light by two stops
     * (allowing 1/4 of the prior amount of light to the sensor).</p>
     * <p>It may take several frames before the lens filter density changes
     * to the requested value. While the filter density is still changing,
     * {@link CaptureResult#LENS_STATE android.lens.state} will be set to MOVING.</p>
     * <p><b>Units</b>: Exposure Value (EV)</p>
     * <p><b>Range of valid values:</b><br>
     * {@link CameraCharacteristics#LENS_INFO_AVAILABLE_FILTER_DENSITIES android.lens.info.availableFilterDensities}</p>
     * <p><b>Optional</b> - This value may be {@code null} on some devices.</p>
     * <p><b>Full capability</b> -
     * Present on all camera devices that report being {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL_FULL HARDWARE_LEVEL_FULL} devices in the
     * {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL android.info.supportedHardwareLevel} key</p>
     *
     * @see CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL
     * @see CameraCharacteristics#LENS_INFO_AVAILABLE_FILTER_DENSITIES
     * @see CaptureResult#LENS_STATE
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> LENS_FILTER_DENSITY;

    /**
     * <p>The desired lens focal length; used for optical zoom.</p>
     * <p>This setting controls the physical focal length of the camera
     * device's lens. Changing the focal length changes the field of
     * view of the camera device, and is usually used for optical zoom.</p>
     * <p>Like {@link CaptureRequest#LENS_FOCUS_DISTANCE android.lens.focusDistance} and {@link CaptureRequest#LENS_APERTURE android.lens.aperture}, this
     * setting won't be applied instantaneously, and it may take several
     * frames before the lens can change to the requested focal length.
     * While the focal length is still changing, {@link CaptureResult#LENS_STATE android.lens.state} will
     * be set to MOVING.</p>
     * <p>Optical zoom will not be supported on most devices.</p>
     * <p><b>Units</b>: Millimeters</p>
     * <p><b>Range of valid values:</b><br>
     * {@link CameraCharacteristics#LENS_INFO_AVAILABLE_FOCAL_LENGTHS android.lens.info.availableFocalLengths}</p>
     * <p>This key is available on all devices.</p>
     *
     * @see CaptureRequest#LENS_APERTURE
     * @see CaptureRequest#LENS_FOCUS_DISTANCE
     * @see CameraCharacteristics#LENS_INFO_AVAILABLE_FOCAL_LENGTHS
     * @see CaptureResult#LENS_STATE
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> LENS_FOCAL_LENGTH;

    /**
     * <p>Desired distance to plane of sharpest focus,
     * measured from frontmost surface of the lens.</p>
     * <p>This control can be used for setting manual focus, on devices that support
     * the MANUAL_SENSOR capability and have a variable-focus lens (see
     * {@link CameraCharacteristics#LENS_INFO_MINIMUM_FOCUS_DISTANCE android.lens.info.minimumFocusDistance}).</p>
     * <p>A value of <code>0.0f</code> means infinity focus. The value set will be clamped to
     * <code>[0.0f, {@link CameraCharacteristics#LENS_INFO_MINIMUM_FOCUS_DISTANCE android.lens.info.minimumFocusDistance}]</code>.</p>
     * <p>Like {@link CaptureRequest#LENS_FOCAL_LENGTH android.lens.focalLength}, this setting won't be applied
     * instantaneously, and it may take several frames before the lens
     * can move to the requested focus distance. While the lens is still moving,
     * {@link CaptureResult#LENS_STATE android.lens.state} will be set to MOVING.</p>
     * <p>LEGACY devices support at most setting this to <code>0.0f</code>
     * for infinity focus.</p>
     * <p><b>Units</b>: See {@link CameraCharacteristics#LENS_INFO_FOCUS_DISTANCE_CALIBRATION android.lens.info.focusDistanceCalibration} for details</p>
     * <p><b>Range of valid values:</b><br>
     * &gt;= 0</p>
     * <p><b>Optional</b> - This value may be {@code null} on some devices.</p>
     * <p><b>Full capability</b> -
     * Present on all camera devices that report being {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL_FULL HARDWARE_LEVEL_FULL} devices in the
     * {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL android.info.supportedHardwareLevel} key</p>
     *
     * @see CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL
     * @see CaptureRequest#LENS_FOCAL_LENGTH
     * @see CameraCharacteristics#LENS_INFO_FOCUS_DISTANCE_CALIBRATION
     * @see CameraCharacteristics#LENS_INFO_MINIMUM_FOCUS_DISTANCE
     * @see CaptureResult#LENS_STATE
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> LENS_FOCUS_DISTANCE;

    /**
     * <p>Sets whether the camera device uses optical image stabilization (OIS)
     * when capturing images.</p>
     * <p>OIS is used to compensate for motion blur due to small
     * movements of the camera during capture. Unlike digital image
     * stabilization ({@link CaptureRequest#CONTROL_VIDEO_STABILIZATION_MODE android.control.videoStabilizationMode}), OIS
     * makes use of mechanical elements to stabilize the camera
     * sensor, and thus allows for longer exposure times before
     * camera shake becomes apparent.</p>
     * <p>Switching between different optical stabilization modes may take several
     * frames to initialize, the camera device will report the current mode in
     * capture result metadata. For example, When "ON" mode is requested, the
     * optical stabilization modes in the first several capture results may still
     * be "OFF", and it will become "ON" when the initialization is done.</p>
     * <p>If a camera device supports both OIS and digital image stabilization
     * ({@link CaptureRequest#CONTROL_VIDEO_STABILIZATION_MODE android.control.videoStabilizationMode}), turning both modes on may produce undesirable
     * interaction, so it is recommended not to enable both at the same time.</p>
     * <p>Not all devices will support OIS; see
     * {@link CameraCharacteristics#LENS_INFO_AVAILABLE_OPTICAL_STABILIZATION android.lens.info.availableOpticalStabilization} for
     * available controls.</p>
     * <p><b>Possible values:</b>
     * <ul>
     *   <li>{@link #LENS_OPTICAL_STABILIZATION_MODE_OFF OFF}</li>
     *   <li>{@link #LENS_OPTICAL_STABILIZATION_MODE_ON ON}</li>
     * </ul></p>
     * <p><b>Available values for this device:</b><br>
     * {@link CameraCharacteristics#LENS_INFO_AVAILABLE_OPTICAL_STABILIZATION android.lens.info.availableOpticalStabilization}</p>
     * <p><b>Optional</b> - This value may be {@code null} on some devices.</p>
     * <p><b>Limited capability</b> -
     * Present on all camera devices that report being at least {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL_LIMITED HARDWARE_LEVEL_LIMITED} devices in the
     * {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL android.info.supportedHardwareLevel} key</p>
     *
     * @see CaptureRequest#CONTROL_VIDEO_STABILIZATION_MODE
     * @see CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL
     * @see CameraCharacteristics#LENS_INFO_AVAILABLE_OPTICAL_STABILIZATION
     * @see #LENS_OPTICAL_STABILIZATION_MODE_OFF
     * @see #LENS_OPTICAL_STABILIZATION_MODE_ON
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> LENS_OPTICAL_STABILIZATION_MODE;

    /**
     * <p>Mode of operation for the noise reduction algorithm.</p>
     * <p>The noise reduction algorithm attempts to improve image quality by removing
     * excessive noise added by the capture process, especially in dark conditions.
     * OFF means no noise reduction will be applied by the camera device.</p>
     * <p>FAST/HIGH_QUALITY both mean camera device determined noise filtering
     * will be applied. HIGH_QUALITY mode indicates that the camera device
     * will use the highest-quality noise filtering algorithms,
     * even if it slows down capture rate. FAST means the camera device will not
     * slow down capture rate when applying noise filtering.</p>
     * <p><b>Possible values:</b>
     * <ul>
     *   <li>{@link #NOISE_REDUCTION_MODE_OFF OFF}</li>
     *   <li>{@link #NOISE_REDUCTION_MODE_FAST FAST}</li>
     *   <li>{@link #NOISE_REDUCTION_MODE_HIGH_QUALITY HIGH_QUALITY}</li>
     * </ul></p>
     * <p><b>Available values for this device:</b><br>
     * {@link CameraCharacteristics#NOISE_REDUCTION_AVAILABLE_NOISE_REDUCTION_MODES android.noiseReduction.availableNoiseReductionModes}</p>
     * <p><b>Optional</b> - This value may be {@code null} on some devices.</p>
     * <p><b>Full capability</b> -
     * Present on all camera devices that report being {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL_FULL HARDWARE_LEVEL_FULL} devices in the
     * {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL android.info.supportedHardwareLevel} key</p>
     *
     * @see CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL
     * @see CameraCharacteristics#NOISE_REDUCTION_AVAILABLE_NOISE_REDUCTION_MODES
     * @see #NOISE_REDUCTION_MODE_OFF
     * @see #NOISE_REDUCTION_MODE_FAST
     * @see #NOISE_REDUCTION_MODE_HIGH_QUALITY
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> NOISE_REDUCTION_MODE;

    /**
     * <p>An application-specified ID for the current
     * request. Must be maintained unchanged in output
     * frame</p>
     * <p><b>Units</b>: arbitrary integer assigned by application</p>
     * <p><b>Range of valid values:</b><br>
     * Any int</p>
     * <p><b>Optional</b> - This value may be {@code null} on some devices.</p>
     * @hide
     */
    static const AutoPtr<ICaptureRequestKey> REQUEST_ID;

    /**
     * <p>The desired region of the sensor to read out for this capture.</p>
     * <p>This control can be used to implement digital zoom.</p>
     * <p>The crop region coordinate system is based off
     * {@link CameraCharacteristics#SENSOR_INFO_ACTIVE_ARRAY_SIZE android.sensor.info.activeArraySize}, with <code>(0, 0)</code> being the
     * top-left corner of the sensor active array.</p>
     * <p>Output streams use this rectangle to produce their output,
     * cropping to a smaller region if necessary to maintain the
     * stream's aspect ratio, then scaling the sensor input to
     * match the output's configured resolution.</p>
     * <p>The crop region is applied after the RAW to other color
     * space (e.g. YUV) conversion. Since raw streams
     * (e.g. RAW16) don't have the conversion stage, they are not
     * croppable. The crop region will be ignored by raw streams.</p>
     * <p>For non-raw streams, any additional per-stream cropping will
     * be done to maximize the final pixel area of the stream.</p>
     * <p>For example, if the crop region is set to a 4:3 aspect
     * ratio, then 4:3 streams will use the exact crop
     * region. 16:9 streams will further crop vertically
     * (letterbox).</p>
     * <p>Conversely, if the crop region is set to a 16:9, then 4:3
     * outputs will crop horizontally (pillarbox), and 16:9
     * streams will match exactly. These additional crops will
     * be centered within the crop region.</p>
     * <p>The width and height of the crop region cannot
     * be set to be smaller than
     * <code>floor( activeArraySize.width / {@link CameraCharacteristics#SCALER_AVAILABLE_MAX_DIGITAL_ZOOM android.scaler.availableMaxDigitalZoom} )</code> and
     * <code>floor( activeArraySize.height / {@link CameraCharacteristics#SCALER_AVAILABLE_MAX_DIGITAL_ZOOM android.scaler.availableMaxDigitalZoom} )</code>, respectively.</p>
     * <p>The camera device may adjust the crop region to account
     * for rounding and other hardware requirements; the final
     * crop region used will be included in the output capture
     * result.</p>
     * <p><b>Units</b>: Pixel coordinates relative to
     * {@link CameraCharacteristics#SENSOR_INFO_ACTIVE_ARRAY_SIZE android.sensor.info.activeArraySize}</p>
     * <p>This key is available on all devices.</p>
     *
     * @see CameraCharacteristics#SCALER_AVAILABLE_MAX_DIGITAL_ZOOM
     * @see CameraCharacteristics#SENSOR_INFO_ACTIVE_ARRAY_SIZE
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> SCALER_CROP_REGION;

    /**
     * <p>Duration each pixel is exposed to
     * light.</p>
     * <p>If the sensor can't expose this exact duration, it will shorten the
     * duration exposed to the nearest possible value (rather than expose longer).
     * The final exposure time used will be available in the output capture result.</p>
     * <p>This control is only effective if {@link CaptureRequest#CONTROL_AE_MODE android.control.aeMode} or {@link CaptureRequest#CONTROL_MODE android.control.mode} is set to
     * OFF; otherwise the auto-exposure algorithm will override this value.</p>
     * <p><b>Units</b>: Nanoseconds</p>
     * <p><b>Range of valid values:</b><br>
     * {@link CameraCharacteristics#SENSOR_INFO_EXPOSURE_TIME_RANGE android.sensor.info.exposureTimeRange}</p>
     * <p><b>Optional</b> - This value may be {@code null} on some devices.</p>
     * <p><b>Full capability</b> -
     * Present on all camera devices that report being {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL_FULL HARDWARE_LEVEL_FULL} devices in the
     * {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL android.info.supportedHardwareLevel} key</p>
     *
     * @see CaptureRequest#CONTROL_AE_MODE
     * @see CaptureRequest#CONTROL_MODE
     * @see CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL
     * @see CameraCharacteristics#SENSOR_INFO_EXPOSURE_TIME_RANGE
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> SENSOR_EXPOSURE_TIME;

    /**
     * <p>Duration from start of frame exposure to
     * start of next frame exposure.</p>
     * <p>The maximum frame rate that can be supported by a camera subsystem is
     * a function of many factors:</p>
     * <ul>
     * <li>Requested resolutions of output image streams</li>
     * <li>Availability of binning / skipping modes on the imager</li>
     * <li>The bandwidth of the imager interface</li>
     * <li>The bandwidth of the various ISP processing blocks</li>
     * </ul>
     * <p>Since these factors can vary greatly between different ISPs and
     * sensors, the camera abstraction tries to represent the bandwidth
     * restrictions with as simple a model as possible.</p>
     * <p>The model presented has the following characteristics:</p>
     * <ul>
     * <li>The image sensor is always configured to output the smallest
     * resolution possible given the application's requested output stream
     * sizes.  The smallest resolution is defined as being at least as large
     * as the largest requested output stream size; the camera pipeline must
     * never digitally upsample sensor data when the crop region covers the
     * whole sensor. In general, this means that if only small output stream
     * resolutions are configured, the sensor can provide a higher frame
     * rate.</li>
     * <li>Since any request may use any or all the currently configured
     * output streams, the sensor and ISP must be configured to support
     * scaling a single capture to all the streams at the same time.  This
     * means the camera pipeline must be ready to produce the largest
     * requested output size without any delay.  Therefore, the overall
     * frame rate of a given configured stream set is governed only by the
     * largest requested stream resolution.</li>
     * <li>Using more than one output stream in a request does not affect the
     * frame duration.</li>
     * <li>Certain format-streams may need to do additional background processing
     * before data is consumed/produced by that stream. These processors
     * can run concurrently to the rest of the camera pipeline, but
     * cannot process more than 1 capture at a time.</li>
     * </ul>
     * <p>The necessary information for the application, given the model above,
     * is provided via the {@link CameraCharacteristics#SCALER_STREAM_CONFIGURATION_MAP android.scaler.streamConfigurationMap} field
     * using StreamConfigurationMap#getOutputMinFrameDuration(int, Size).
     * These are used to determine the maximum frame rate / minimum frame
     * duration that is possible for a given stream configuration.</p>
     * <p>Specifically, the application can use the following rules to
     * determine the minimum frame duration it can request from the camera
     * device:</p>
     * <ol>
     * <li>Let the set of currently configured input/output streams
     * be called <code>S</code>.</li>
     * <li>Find the minimum frame durations for each stream in <code>S</code>, by
     * looking it up in {@link CameraCharacteristics#SCALER_STREAM_CONFIGURATION_MAP android.scaler.streamConfigurationMap} using
     * StreamConfigurationMap#getOutputMinFrameDuration(int, Size) (with
     * its respective size/format). Let this set of frame durations be called
     * <code>F</code>.</li>
     * <li>For any given request <code>R</code>, the minimum frame duration allowed
     * for <code>R</code> is the maximum out of all values in <code>F</code>. Let the streams
     * used in <code>R</code> be called <code>S_r</code>.</li>
     * </ol>
     * <p>If none of the streams in <code>S_r</code> have a stall time (listed in
     * StreamConfigurationMap#getOutputStallDuration(int,Size) using its
     * respective size/format), then the frame duration in
     * <code>F</code> determines the steady state frame rate that the application will
     * get if it uses <code>R</code> as a repeating request. Let this special kind
     * of request be called <code>Rsimple</code>.</p>
     * <p>A repeating request <code>Rsimple</code> can be <em>occasionally</em> interleaved
     * by a single capture of a new request <code>Rstall</code> (which has at least
     * one in-use stream with a non-0 stall time) and if <code>Rstall</code> has the
     * same minimum frame duration this will not cause a frame rate loss
     * if all buffers from the previous <code>Rstall</code> have already been
     * delivered.</p>
     * <p>For more details about stalling, see
     * StreamConfigurationMap#getOutputStallDuration(int,Size).</p>
     * <p>This control is only effective if {@link CaptureRequest#CONTROL_AE_MODE android.control.aeMode} or {@link CaptureRequest#CONTROL_MODE android.control.mode} is set to
     * OFF; otherwise the auto-exposure algorithm will override this value.</p>
     * <p><b>Units</b>: Nanoseconds</p>
     * <p><b>Range of valid values:</b><br>
     * See {@link CameraCharacteristics#SENSOR_INFO_MAX_FRAME_DURATION android.sensor.info.maxFrameDuration},
     * {@link CameraCharacteristics#SCALER_STREAM_CONFIGURATION_MAP android.scaler.streamConfigurationMap}. The duration
     * is capped to <code>max(duration, exposureTime + overhead)</code>.</p>
     * <p><b>Optional</b> - This value may be {@code null} on some devices.</p>
     * <p><b>Full capability</b> -
     * Present on all camera devices that report being {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL_FULL HARDWARE_LEVEL_FULL} devices in the
     * {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL android.info.supportedHardwareLevel} key</p>
     *
     * @see CaptureRequest#CONTROL_AE_MODE
     * @see CaptureRequest#CONTROL_MODE
     * @see CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL
     * @see CameraCharacteristics#SCALER_STREAM_CONFIGURATION_MAP
     * @see CameraCharacteristics#SENSOR_INFO_MAX_FRAME_DURATION
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> SENSOR_FRAME_DURATION;

    /**
     * <p>The amount of gain applied to sensor data
     * before processing.</p>
     * <p>The sensitivity is the standard ISO sensitivity value,
     * as defined in ISO 12232:2006.</p>
     * <p>The sensitivity must be within {@link CameraCharacteristics#SENSOR_INFO_SENSITIVITY_RANGE android.sensor.info.sensitivityRange}, and
     * if if it less than {@link CameraCharacteristics#SENSOR_MAX_ANALOG_SENSITIVITY android.sensor.maxAnalogSensitivity}, the camera device
     * is guaranteed to use only analog amplification for applying the gain.</p>
     * <p>If the camera device cannot apply the exact sensitivity
     * requested, it will reduce the gain to the nearest supported
     * value. The final sensitivity used will be available in the
     * output capture result.</p>
     * <p><b>Units</b>: ISO arithmetic units</p>
     * <p><b>Range of valid values:</b><br>
     * {@link CameraCharacteristics#SENSOR_INFO_SENSITIVITY_RANGE android.sensor.info.sensitivityRange}</p>
     * <p><b>Optional</b> - This value may be {@code null} on some devices.</p>
     * <p><b>Full capability</b> -
     * Present on all camera devices that report being {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL_FULL HARDWARE_LEVEL_FULL} devices in the
     * {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL android.info.supportedHardwareLevel} key</p>
     *
     * @see CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL
     * @see CameraCharacteristics#SENSOR_INFO_SENSITIVITY_RANGE
     * @see CameraCharacteristics#SENSOR_MAX_ANALOG_SENSITIVITY
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> SENSOR_SENSITIVITY;

    /**
     * <p>A pixel <code>[R, G_even, G_odd, B]</code> that supplies the test pattern
     * when {@link CaptureRequest#SENSOR_TEST_PATTERN_MODE android.sensor.testPatternMode} is SOLID_COLOR.</p>
     * <p>Each color channel is treated as an unsigned 32-bit integer.
     * The camera device then uses the most significant X bits
     * that correspond to how many bits are in its Bayer raw sensor
     * output.</p>
     * <p>For example, a sensor with RAW10 Bayer output would use the
     * 10 most significant bits from each color channel.</p>
     * <p><b>Optional</b> - This value may be {@code null} on some devices.</p>
     *
     * @see CaptureRequest#SENSOR_TEST_PATTERN_MODE
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> SENSOR_TEST_PATTERN_DATA;

    /**
     * <p>When enabled, the sensor sends a test pattern instead of
     * doing a real exposure from the camera.</p>
     * <p>When a test pattern is enabled, all manual sensor controls specified
     * by android.sensor.* will be ignored. All other controls should
     * work as normal.</p>
     * <p>For example, if manual flash is enabled, flash firing should still
     * occur (and that the test pattern remain unmodified, since the flash
     * would not actually affect it).</p>
     * <p>Defaults to OFF.</p>
     * <p><b>Possible values:</b>
     * <ul>
     *   <li>{@link #SENSOR_TEST_PATTERN_MODE_OFF OFF}</li>
     *   <li>{@link #SENSOR_TEST_PATTERN_MODE_SOLID_COLOR SOLID_COLOR}</li>
     *   <li>{@link #SENSOR_TEST_PATTERN_MODE_COLOR_BARS COLOR_BARS}</li>
     *   <li>{@link #SENSOR_TEST_PATTERN_MODE_COLOR_BARS_FADE_TO_GRAY COLOR_BARS_FADE_TO_GRAY}</li>
     *   <li>{@link #SENSOR_TEST_PATTERN_MODE_PN9 PN9}</li>
     *   <li>{@link #SENSOR_TEST_PATTERN_MODE_CUSTOM1 CUSTOM1}</li>
     * </ul></p>
     * <p><b>Available values for this device:</b><br>
     * {@link CameraCharacteristics#SENSOR_AVAILABLE_TEST_PATTERN_MODES android.sensor.availableTestPatternModes}</p>
     * <p><b>Optional</b> - This value may be {@code null} on some devices.</p>
     *
     * @see CameraCharacteristics#SENSOR_AVAILABLE_TEST_PATTERN_MODES
     * @see #SENSOR_TEST_PATTERN_MODE_OFF
     * @see #SENSOR_TEST_PATTERN_MODE_SOLID_COLOR
     * @see #SENSOR_TEST_PATTERN_MODE_COLOR_BARS
     * @see #SENSOR_TEST_PATTERN_MODE_COLOR_BARS_FADE_TO_GRAY
     * @see #SENSOR_TEST_PATTERN_MODE_PN9
     * @see #SENSOR_TEST_PATTERN_MODE_CUSTOM1
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> SENSOR_TEST_PATTERN_MODE;

    /**
     * <p>Quality of lens shading correction applied
     * to the image data.</p>
     * <p>When set to OFF mode, no lens shading correction will be applied by the
     * camera device, and an identity lens shading map data will be provided
     * if <code>{@link CaptureRequest#STATISTICS_LENS_SHADING_MAP_MODE android.statistics.lensShadingMapMode} == ON</code>. For example, for lens
     * shading map with size of <code>[ 4, 3 ]</code>,
     * the output {@link CaptureResult#STATISTICS_LENS_SHADING_CORRECTION_MAP android.statistics.lensShadingCorrectionMap} for this case will be an identity
     * map shown below:</p>
     * <pre><code>[ 1.0, 1.0, 1.0, 1.0,  1.0, 1.0, 1.0, 1.0,
     *  1.0, 1.0, 1.0, 1.0,  1.0, 1.0, 1.0, 1.0,
     *  1.0, 1.0, 1.0, 1.0,  1.0, 1.0, 1.0, 1.0,
     *  1.0, 1.0, 1.0, 1.0,  1.0, 1.0, 1.0, 1.0,
     *  1.0, 1.0, 1.0, 1.0,  1.0, 1.0, 1.0, 1.0,
     *  1.0, 1.0, 1.0, 1.0,  1.0, 1.0, 1.0, 1.0 ]
     * </code></pre>
     * <p>When set to other modes, lens shading correction will be applied by the camera
     * device. Applications can request lens shading map data by setting
     * {@link CaptureRequest#STATISTICS_LENS_SHADING_MAP_MODE android.statistics.lensShadingMapMode} to ON, and then the camera device will provide lens
     * shading map data in {@link CaptureResult#STATISTICS_LENS_SHADING_CORRECTION_MAP android.statistics.lensShadingCorrectionMap}; the returned shading map
     * data will be the one applied by the camera device for this capture request.</p>
     * <p>The shading map data may depend on the auto-exposure (AE) and AWB statistics, therefore
     * the reliability of the map data may be affected by the AE and AWB algorithms. When AE and
     * AWB are in AUTO modes({@link CaptureRequest#CONTROL_AE_MODE android.control.aeMode} <code>!=</code> OFF and {@link CaptureRequest#CONTROL_AWB_MODE android.control.awbMode} <code>!=</code>
     * OFF), to get best results, it is recommended that the applications wait for the AE and AWB
     * to be converged before using the returned shading map data.</p>
     * <p><b>Possible values:</b>
     * <ul>
     *   <li>{@link #SHADING_MODE_OFF OFF}</li>
     *   <li>{@link #SHADING_MODE_FAST FAST}</li>
     *   <li>{@link #SHADING_MODE_HIGH_QUALITY HIGH_QUALITY}</li>
     * </ul></p>
     * <p><b>Optional</b> - This value may be {@code null} on some devices.</p>
     * <p><b>Full capability</b> -
     * Present on all camera devices that report being {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL_FULL HARDWARE_LEVEL_FULL} devices in the
     * {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL android.info.supportedHardwareLevel} key</p>
     *
     * @see CaptureRequest#CONTROL_AE_MODE
     * @see CaptureRequest#CONTROL_AWB_MODE
     * @see CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL
     * @see CaptureResult#STATISTICS_LENS_SHADING_CORRECTION_MAP
     * @see CaptureRequest#STATISTICS_LENS_SHADING_MAP_MODE
     * @see #SHADING_MODE_OFF
     * @see #SHADING_MODE_FAST
     * @see #SHADING_MODE_HIGH_QUALITY
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> SHADING_MODE;

    /**
     * <p>Operating mode for the face detector
     * unit.</p>
     * <p>Whether face detection is enabled, and whether it
     * should output just the basic fields or the full set of
     * fields.</p>
     * <p><b>Possible values:</b>
     * <ul>
     *   <li>{@link #STATISTICS_FACE_DETECT_MODE_OFF OFF}</li>
     *   <li>{@link #STATISTICS_FACE_DETECT_MODE_SIMPLE SIMPLE}</li>
     *   <li>{@link #STATISTICS_FACE_DETECT_MODE_FULL FULL}</li>
     * </ul></p>
     * <p><b>Available values for this device:</b><br>
     * {@link CameraCharacteristics#STATISTICS_INFO_AVAILABLE_FACE_DETECT_MODES android.statistics.info.availableFaceDetectModes}</p>
     * <p>This key is available on all devices.</p>
     *
     * @see CameraCharacteristics#STATISTICS_INFO_AVAILABLE_FACE_DETECT_MODES
     * @see #STATISTICS_FACE_DETECT_MODE_OFF
     * @see #STATISTICS_FACE_DETECT_MODE_SIMPLE
     * @see #STATISTICS_FACE_DETECT_MODE_FULL
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> STATISTICS_FACE_DETECT_MODE;

    /**
     * <p>Operating mode for hot pixel map generation.</p>
     * <p>If set to <code>true</code>, a hot pixel map is returned in {@link CaptureResult#STATISTICS_HOT_PIXEL_MAP android.statistics.hotPixelMap}.
     * If set to <code>false</code>, no hot pixel map will be returned.</p>
     * <p><b>Range of valid values:</b><br>
     * {@link CameraCharacteristics#STATISTICS_INFO_AVAILABLE_HOT_PIXEL_MAP_MODES android.statistics.info.availableHotPixelMapModes}</p>
     * <p><b>Optional</b> - This value may be {@code null} on some devices.</p>
     *
     * @see CaptureResult#STATISTICS_HOT_PIXEL_MAP
     * @see CameraCharacteristics#STATISTICS_INFO_AVAILABLE_HOT_PIXEL_MAP_MODES
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> STATISTICS_HOT_PIXEL_MAP_MODE;

    /**
     * <p>Whether the camera device will output the lens
     * shading map in output result metadata.</p>
     * <p>When set to ON,
     * android.statistics.lensShadingMap will be provided in
     * the output result metadata.</p>
     * <p>ON is always supported on devices with the RAW capability.</p>
     * <p><b>Possible values:</b>
     * <ul>
     *   <li>{@link #STATISTICS_LENS_SHADING_MAP_MODE_OFF OFF}</li>
     *   <li>{@link #STATISTICS_LENS_SHADING_MAP_MODE_ON ON}</li>
     * </ul></p>
     * <p><b>Optional</b> - This value may be {@code null} on some devices.</p>
     * <p><b>Full capability</b> -
     * Present on all camera devices that report being {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL_FULL HARDWARE_LEVEL_FULL} devices in the
     * {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL android.info.supportedHardwareLevel} key</p>
     *
     * @see CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL
     * @see #STATISTICS_LENS_SHADING_MAP_MODE_OFF
     * @see #STATISTICS_LENS_SHADING_MAP_MODE_ON
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> STATISTICS_LENS_SHADING_MAP_MODE;

    /**
     * <p>Tonemapping / contrast / gamma curve for the blue
     * channel, to use when {@link CaptureRequest#TONEMAP_MODE android.tonemap.mode} is
     * CONTRAST_CURVE.</p>
     * <p>See android.tonemap.curveRed for more details.</p>
     * <p><b>Optional</b> - This value may be {@code null} on some devices.</p>
     * <p><b>Full capability</b> -
     * Present on all camera devices that report being {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL_FULL HARDWARE_LEVEL_FULL} devices in the
     * {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL android.info.supportedHardwareLevel} key</p>
     *
     * @see CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL
     * @see CaptureRequest#TONEMAP_MODE
     * @hide
     */
    static const AutoPtr<ICaptureRequestKey> TONEMAP_CURVE_BLUE;

    /**
     * <p>Tonemapping / contrast / gamma curve for the green
     * channel, to use when {@link CaptureRequest#TONEMAP_MODE android.tonemap.mode} is
     * CONTRAST_CURVE.</p>
     * <p>See android.tonemap.curveRed for more details.</p>
     * <p><b>Optional</b> - This value may be {@code null} on some devices.</p>
     * <p><b>Full capability</b> -
     * Present on all camera devices that report being {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL_FULL HARDWARE_LEVEL_FULL} devices in the
     * {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL android.info.supportedHardwareLevel} key</p>
     *
     * @see CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL
     * @see CaptureRequest#TONEMAP_MODE
     * @hide
     */
    static const AutoPtr<ICaptureRequestKey> TONEMAP_CURVE_GREEN;

    /**
     * <p>Tonemapping / contrast / gamma curve for the red
     * channel, to use when {@link CaptureRequest#TONEMAP_MODE android.tonemap.mode} is
     * CONTRAST_CURVE.</p>
     * <p>Each channel's curve is defined by an array of control points:</p>
     * <pre><code>android.tonemap.curveRed =
     *   [ P0in, P0out, P1in, P1out, P2in, P2out, P3in, P3out, ..., PNin, PNout ]
     * 2 &lt;= N &lt;= {@link CameraCharacteristics#TONEMAP_MAX_CURVE_POINTS android.tonemap.maxCurvePoints}</code></pre>
     * <p>These are sorted in order of increasing <code>Pin</code>; it is
     * required that input values 0.0 and 1.0 are included in the list to
     * define a complete mapping. For input values between control points,
     * the camera device must linearly interpolate between the control
     * points.</p>
     * <p>Each curve can have an independent number of points, and the number
     * of points can be less than max (that is, the request doesn't have to
     * always provide a curve with number of points equivalent to
     * {@link CameraCharacteristics#TONEMAP_MAX_CURVE_POINTS android.tonemap.maxCurvePoints}).</p>
     * <p>A few examples, and their corresponding graphical mappings; these
     * only specify the red channel and the precision is limited to 4
     * digits, for conciseness.</p>
     * <p>Linear mapping:</p>
     * <pre><code>android.tonemap.curveRed = [ 0, 0, 1.0, 1.0 ]
     * </code></pre>
     * <p><img alt="Linear mapping curve" src="../../../../images/camera2/metadata/android.tonemap.curveRed/linear_tonemap.png" /></p>
     * <p>Invert mapping:</p>
     * <pre><code>android.tonemap.curveRed = [ 0, 1.0, 1.0, 0 ]
     * </code></pre>
     * <p><img alt="Inverting mapping curve" src="../../../../images/camera2/metadata/android.tonemap.curveRed/inverse_tonemap.png" /></p>
     * <p>Gamma 1/2.2 mapping, with 16 control points:</p>
     * <pre><code>android.tonemap.curveRed = [
     *   0.0000, 0.0000, 0.0667, 0.2920, 0.1333, 0.4002, 0.2000, 0.4812,
     *   0.2667, 0.5484, 0.3333, 0.6069, 0.4000, 0.6594, 0.4667, 0.7072,
     *   0.5333, 0.7515, 0.6000, 0.7928, 0.6667, 0.8317, 0.7333, 0.8685,
     *   0.8000, 0.9035, 0.8667, 0.9370, 0.9333, 0.9691, 1.0000, 1.0000 ]
     * </code></pre>
     * <p><img alt="Gamma = 1/2.2 tonemapping curve" src="../../../../images/camera2/metadata/android.tonemap.curveRed/gamma_tonemap.png" /></p>
     * <p>Standard sRGB gamma mapping, per IEC 61966-2-1:1999, with 16 control points:</p>
     * <pre><code>android.tonemap.curveRed = [
     *   0.0000, 0.0000, 0.0667, 0.2864, 0.1333, 0.4007, 0.2000, 0.4845,
     *   0.2667, 0.5532, 0.3333, 0.6125, 0.4000, 0.6652, 0.4667, 0.7130,
     *   0.5333, 0.7569, 0.6000, 0.7977, 0.6667, 0.8360, 0.7333, 0.8721,
     *   0.8000, 0.9063, 0.8667, 0.9389, 0.9333, 0.9701, 1.0000, 1.0000 ]
     * </code></pre>
     * <p><img alt="sRGB tonemapping curve" src="../../../../images/camera2/metadata/android.tonemap.curveRed/srgb_tonemap.png" /></p>
     * <p><b>Range of valid values:</b><br>
     * 0-1 on both input and output coordinates, normalized
     * as a floating-point value such that 0 == black and 1 == white.</p>
     * <p><b>Optional</b> - This value may be {@code null} on some devices.</p>
     * <p><b>Full capability</b> -
     * Present on all camera devices that report being {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL_FULL HARDWARE_LEVEL_FULL} devices in the
     * {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL android.info.supportedHardwareLevel} key</p>
     *
     * @see CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL
     * @see CameraCharacteristics#TONEMAP_MAX_CURVE_POINTS
     * @see CaptureRequest#TONEMAP_MODE
     * @hide
     */
    static const AutoPtr<ICaptureRequestKey> TONEMAP_CURVE_RED;

    /**
     * <p>Tonemapping / contrast / gamma curve to use when {@link CaptureRequest#TONEMAP_MODE android.tonemap.mode}
     * is CONTRAST_CURVE.</p>
     * <p>The tonemapCurve consist of three curves for each of red, green, and blue
     * channels respectively. The following example uses the red channel as an
     * example. The same logic applies to green and blue channel.
     * Each channel's curve is defined by an array of control points:</p>
     * <pre><code>curveRed =
     *   [ P0(in, out), P1(in, out), P2(in, out), P3(in, out), ..., PN(in, out) ]
     * 2 &lt;= N &lt;= {@link CameraCharacteristics#TONEMAP_MAX_CURVE_POINTS android.tonemap.maxCurvePoints}</code></pre>
     * <p>These are sorted in order of increasing <code>Pin</code>; it is always
     * guaranteed that input values 0.0 and 1.0 are included in the list to
     * define a complete mapping. For input values between control points,
     * the camera device must linearly interpolate between the control
     * points.</p>
     * <p>Each curve can have an independent number of points, and the number
     * of points can be less than max (that is, the request doesn't have to
     * always provide a curve with number of points equivalent to
     * {@link CameraCharacteristics#TONEMAP_MAX_CURVE_POINTS android.tonemap.maxCurvePoints}).</p>
     * <p>A few examples, and their corresponding graphical mappings; these
     * only specify the red channel and the precision is limited to 4
     * digits, for conciseness.</p>
     * <p>Linear mapping:</p>
     * <pre><code>curveRed = [ (0, 0), (1.0, 1.0) ]
     * </code></pre>
     * <p><img alt="Linear mapping curve" src="../../../../images/camera2/metadata/android.tonemap.curveRed/linear_tonemap.png" /></p>
     * <p>Invert mapping:</p>
     * <pre><code>curveRed = [ (0, 1.0), (1.0, 0) ]
     * </code></pre>
     * <p><img alt="Inverting mapping curve" src="../../../../images/camera2/metadata/android.tonemap.curveRed/inverse_tonemap.png" /></p>
     * <p>Gamma 1/2.2 mapping, with 16 control points:</p>
     * <pre><code>curveRed = [
     *   (0.0000, 0.0000), (0.0667, 0.2920), (0.1333, 0.4002), (0.2000, 0.4812),
     *   (0.2667, 0.5484), (0.3333, 0.6069), (0.4000, 0.6594), (0.4667, 0.7072),
     *   (0.5333, 0.7515), (0.6000, 0.7928), (0.6667, 0.8317), (0.7333, 0.8685),
     *   (0.8000, 0.9035), (0.8667, 0.9370), (0.9333, 0.9691), (1.0000, 1.0000) ]
     * </code></pre>
     * <p><img alt="Gamma = 1/2.2 tonemapping curve" src="../../../../images/camera2/metadata/android.tonemap.curveRed/gamma_tonemap.png" /></p>
     * <p>Standard sRGB gamma mapping, per IEC 61966-2-1:1999, with 16 control points:</p>
     * <pre><code>curveRed = [
     *   (0.0000, 0.0000), (0.0667, 0.2864), (0.1333, 0.4007), (0.2000, 0.4845),
     *   (0.2667, 0.5532), (0.3333, 0.6125), (0.4000, 0.6652), (0.4667, 0.7130),
     *   (0.5333, 0.7569), (0.6000, 0.7977), (0.6667, 0.8360), (0.7333, 0.8721),
     *   (0.8000, 0.9063), (0.8667, 0.9389), (0.9333, 0.9701), (1.0000, 1.0000) ]
     * </code></pre>
     * <p><img alt="sRGB tonemapping curve" src="../../../../images/camera2/metadata/android.tonemap.curveRed/srgb_tonemap.png" /></p>
     * <p><b>Optional</b> - This value may be {@code null} on some devices.</p>
     * <p><b>Full capability</b> -
     * Present on all camera devices that report being {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL_FULL HARDWARE_LEVEL_FULL} devices in the
     * {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL android.info.supportedHardwareLevel} key</p>
     *
     * @see CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL
     * @see CameraCharacteristics#TONEMAP_MAX_CURVE_POINTS
     * @see CaptureRequest#TONEMAP_MODE
     */
    //@PublicKey
    //@SyntheticKey
    static const AutoPtr<ICaptureRequestKey> TONEMAP_CURVE;

    /**
     * <p>High-level global contrast/gamma/tonemapping control.</p>
     * <p>When switching to an application-defined contrast curve by setting
     * {@link CaptureRequest#TONEMAP_MODE android.tonemap.mode} to CONTRAST_CURVE, the curve is defined
     * per-channel with a set of <code>(in, out)</code> points that specify the
     * mapping from input high-bit-depth pixel value to the output
     * low-bit-depth value.  Since the actual pixel ranges of both input
     * and output may change depending on the camera pipeline, the values
     * are specified by normalized floating-point numbers.</p>
     * <p>More-complex color mapping operations such as 3D color look-up
     * tables, selective chroma enhancement, or other non-linear color
     * transforms will be disabled when {@link CaptureRequest#TONEMAP_MODE android.tonemap.mode} is
     * CONTRAST_CURVE.</p>
     * <p>When using either FAST or HIGH_QUALITY, the camera device will
     * emit its own tonemap curve in {@link CaptureRequest#TONEMAP_CURVE android.tonemap.curve}.
     * These values are always available, and as close as possible to the
     * actually used nonlinear/nonglobal transforms.</p>
     * <p>If a request is sent with CONTRAST_CURVE with the camera device's
     * provided curve in FAST or HIGH_QUALITY, the image's tonemap will be
     * roughly the same.</p>
     * <p><b>Possible values:</b>
     * <ul>
     *   <li>{@link #TONEMAP_MODE_CONTRAST_CURVE CONTRAST_CURVE}</li>
     *   <li>{@link #TONEMAP_MODE_FAST FAST}</li>
     *   <li>{@link #TONEMAP_MODE_HIGH_QUALITY HIGH_QUALITY}</li>
     * </ul></p>
     * <p><b>Available values for this device:</b><br>
     * {@link CameraCharacteristics#TONEMAP_AVAILABLE_TONE_MAP_MODES android.tonemap.availableToneMapModes}</p>
     * <p><b>Optional</b> - This value may be {@code null} on some devices.</p>
     * <p><b>Full capability</b> -
     * Present on all camera devices that report being {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL_FULL HARDWARE_LEVEL_FULL} devices in the
     * {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL android.info.supportedHardwareLevel} key</p>
     *
     * @see CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL
     * @see CameraCharacteristics#TONEMAP_AVAILABLE_TONE_MAP_MODES
     * @see CaptureRequest#TONEMAP_CURVE
     * @see CaptureRequest#TONEMAP_MODE
     * @see #TONEMAP_MODE_CONTRAST_CURVE
     * @see #TONEMAP_MODE_FAST
     * @see #TONEMAP_MODE_HIGH_QUALITY
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> TONEMAP_MODE;

    /**
     * <p>This LED is nominally used to indicate to the user
     * that the camera is powered on and may be streaming images back to the
     * Application Processor. In certain rare circumstances, the OS may
     * disable this when video is processed locally and not transmitted to
     * any untrusted applications.</p>
     * <p>In particular, the LED <em>must</em> always be on when the data could be
     * transmitted off the device. The LED <em>should</em> always be on whenever
     * data is stored locally on the device.</p>
     * <p>The LED <em>may</em> be off if a trusted application is using the data that
     * doesn't violate the above rules.</p>
     * <p><b>Optional</b> - This value may be {@code null} on some devices.</p>
     * @hide
     */
    static const AutoPtr<ICaptureRequestKey> LED_TRANSMIT;

    /**
     * <p>Whether black-level compensation is locked
     * to its current values, or is free to vary.</p>
     * <p>When set to <code>true</code> (ON), the values used for black-level
     * compensation will not change until the lock is set to
     * <code>false</code> (OFF).</p>
     * <p>Since changes to certain capture parameters (such as
     * exposure time) may require resetting of black level
     * compensation, the camera device must report whether setting
     * the black level lock was successful in the output result
     * metadata.</p>
     * <p>For example, if a sequence of requests is as follows:</p>
     * <ul>
     * <li>Request 1: Exposure = 10ms, Black level lock = OFF</li>
     * <li>Request 2: Exposure = 10ms, Black level lock = ON</li>
     * <li>Request 3: Exposure = 10ms, Black level lock = ON</li>
     * <li>Request 4: Exposure = 20ms, Black level lock = ON</li>
     * <li>Request 5: Exposure = 20ms, Black level lock = ON</li>
     * <li>Request 6: Exposure = 20ms, Black level lock = ON</li>
     * </ul>
     * <p>And the exposure change in Request 4 requires the camera
     * device to reset the black level offsets, then the output
     * result metadata is expected to be:</p>
     * <ul>
     * <li>Result 1: Exposure = 10ms, Black level lock = OFF</li>
     * <li>Result 2: Exposure = 10ms, Black level lock = ON</li>
     * <li>Result 3: Exposure = 10ms, Black level lock = ON</li>
     * <li>Result 4: Exposure = 20ms, Black level lock = OFF</li>
     * <li>Result 5: Exposure = 20ms, Black level lock = ON</li>
     * <li>Result 6: Exposure = 20ms, Black level lock = ON</li>
     * </ul>
     * <p>This indicates to the application that on frame 4, black
     * levels were reset due to exposure value changes, and pixel
     * values may not be consistent across captures.</p>
     * <p>The camera device will maintain the lock to the extent
     * possible, only overriding the lock to OFF when changes to
     * other request parameters require a black level recalculation
     * or reset.</p>
     * <p><b>Optional</b> - This value may be {@code null} on some devices.</p>
     * <p><b>Full capability</b> -
     * Present on all camera devices that report being {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL_FULL HARDWARE_LEVEL_FULL} devices in the
     * {@link CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL android.info.supportedHardwareLevel} key</p>
     *
     * @see CameraCharacteristics#INFO_SUPPORTED_HARDWARE_LEVEL
     */
    //@PublicKey
    static const AutoPtr<ICaptureRequestKey> BLACK_LEVEL_LOCK;

    /*~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~
     * End generated code
     *~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~O@*/

private:
    AutoPtr<IHashSet> mSurfaceSet;
    AutoPtr<ICameraMetadataNative> mSettings;

    AutoPtr<IInterface> mUserTag;
};

} // namespace Camera2
} // namespace Hardware
} // namespace Droid
} // namespace Elastos

#endif //__ELASTOS_DROID_HARDWARE_CAMERA2_CAPTUREREQUEST_H__
