
#ifndef __ELASTOS_DROID_ANIMATION_CPROPERTYVALUESHOLDERHELPER_H__
#define __ELASTOS_DROID_ANIMATION_CPROPERTYVALUESHOLDERHELPER_H__

#include "_Elastos_Droid_Animation_CPropertyValuesHolderHelper.h"
#include <elastos/core/Singleton.h>

using Elastos::Core::Singleton;
using Elastos::Droid::Utility::IProperty;

namespace Elastos {
namespace Droid {
namespace Animation {

CarClass(CPropertyValuesHolderHelper)
    , public Singleton
    , public IPropertyValuesHolderHelper
{
public:
    CAR_INTERFACE_DECL()

    CAR_SINGLETON_DECL()

    /**
     * Constructs and returns a PropertyValuesHolder with a given property name and
     * set of Int32 values.
     * @param propertyName The name of the property being animated.
     * @param values The values that the named property will animate between.
     * @return PropertyValuesHolder The constructed PropertyValuesHolder object.
     */
    CARAPI OfInt32(
        /* [in] */ const String& propertyName,
        /* [in] */ ArrayOf<Int32>* values,
        /* [out] */ IPropertyValuesHolder** holder);

    /**
     * Constructs and returns a PropertyValuesHolder with a given property and
     * set of Int32 values.
     * @param property The property being animated. Should not be NULL.
     * @param values The values that the property will animate between.
     * @return PropertyValuesHolder The constructed PropertyValuesHolder object.
     */
    CARAPI OfInt32(
        /* [in] */ IProperty* property,
        /* [in] */ ArrayOf<Int32>* values,
        /* [out] */ IPropertyValuesHolder** holder);

    /**
     * Constructs and returns a PropertyValuesHolder with a given property name and
     * set of Float values.
     * @param propertyName The name of the property being animated.
     * @param values The values that the named property will animate between.
     * @return PropertyValuesHolder The constructed PropertyValuesHolder object.
     */
    CARAPI OfFloat(
        /* [in] */ const String& propertyName,
        /* [in] */ ArrayOf<Float>* values,
        /* [out] */ IPropertyValuesHolder** holder);

    /**
     * Constructs and returns a PropertyValuesHolder with a given property and
     * set of Float values.
     * @param property The property being animated. Should not be NULL.
     * @param values The values that the property will animate between.
     * @return PropertyValuesHolder The constructed PropertyValuesHolder object.
     */
    CARAPI OfFloat(
        /* [in] */ IProperty* property,
        /* [in] */ ArrayOf<Float>* values,
        /* [out] */ IPropertyValuesHolder** holder);

    /**
     * Constructs and returns a PropertyValuesHolder with a given property name and
     * set of Object values. This variant also takes a TypeEvaluator because the system
     * cannot automatically interpolate between objects of unknown type.
     *
     * @param propertyName The name of the property being animated.
     * @param evaluator A TypeEvaluator that will be called on each animation frame to
     * provide the necessary interpolation between the Object values to derive the animated
     * value.
     * @param values The values that the named property will animate between.
     * @return PropertyValuesHolder The constructed PropertyValuesHolder object.
     */
    CARAPI OfObject(
        /* [in] */ const String& propertyName,
        /* [in] */ ITypeEvaluator* evaluator,
        /* [in] */ ArrayOf<IInterface*>* values,
        /* [out] */ IPropertyValuesHolder** holder);

    /**
     * Constructs and returns a PropertyValuesHolder with a given property and
     * set of Object values. This variant also takes a TypeEvaluator because the system
     * cannot automatically interpolate between objects of unknown type.
     *
     * @param property The property being animated. Should not be NULL.
     * @param evaluator A TypeEvaluator that will be called on each animation frame to
     * provide the necessary interpolation between the Object values to derive the animated
     * value.
     * @param values The values that the property will animate between.
     * @return PropertyValuesHolder The constructed PropertyValuesHolder object.
     */
    CARAPI OfObject(
        /* [in] */ IProperty* property,
        /* [in] */ ITypeEvaluator* evaluator,
        /* [in] */ ArrayOf<IInterface*>* values,
        /* [out] */ IPropertyValuesHolder** holder);

    /**
     * Constructs and returns a PropertyValuesHolder object with the specified property name and set
     * of values. These values can be of any type, but the type should be consistent so that
     * an appropriate {@link android.animation.TypeEvaluator} can be found that matches
     * the common type.
     * <p>If there is only one value, it is assumed to be the end value of an animation,
     * and an initial value will be derived, if possible, by calling a getter function
     * on the object. Also, if any value is NULL, the value will be filled in when the animation
     * starts in the same way. This mechanism of automatically getting NULL values only works
     * if the PropertyValuesHolder object is used in conjunction
     * {@link ObjectAnimator}, and with a getter function
     * derived automatically from <code>propertyName</code>, since otherwise PropertyValuesHolder has
     * no way of determining what the value should be.
     * @param propertyName The name of the property associated with this set of values. This
     * can be the actual property name to be used when using a ObjectAnimator object, or
     * just a name used to get animated values, such as if this object is used with an
     * ValueAnimator object.
     * @param values The set of values to animate between.
     */
    CARAPI OfKeyframe(
        /* [in] */ const String& propertyName,
        /* [in] */ ArrayOf<IKeyframe*>* values,
        /* [out] */ IPropertyValuesHolder** holder);

    /**
     * Constructs and returns a PropertyValuesHolder object with the specified property and set
     * of values. These values can be of any type, but the type should be consistent so that
     * an appropriate {@link android.animation.TypeEvaluator} can be found that matches
     * the common type.
     * <p>If there is only one value, it is assumed to be the end value of an animation,
     * and an initial value will be derived, if possible, by calling the property's
     * {@link android.util.Property#get(Object)} function.
     * Also, if any value is NULL, the value will be filled in when the animation
     * starts in the same way. This mechanism of automatically getting NULL values only works
     * if the PropertyValuesHolder object is used in conjunction with
     * {@link ObjectAnimator}, since otherwise PropertyValuesHolder has
     * no way of determining what the value should be.
     * @param property The property associated with this set of values. Should not be NULL.
     * @param values The set of values to animate between.
     */
    CARAPI OfKeyframe(
        /* [in] */ IProperty* property,
        /* [in] */ ArrayOf<IKeyframe*>* values,
        /* [out] */ IPropertyValuesHolder** holder);
};

} // namespace Animation
} // namepsace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_ANIMATION_CPROPERTYVALUESHOLDERHELPER_H__
